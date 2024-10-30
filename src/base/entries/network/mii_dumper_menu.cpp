#include <base/entries.hpp>

#include <base/pointers.hpp>

#include <Net/NetworkEngine.hpp>
#include <Net/NetworkPlayerDataManager.hpp>

#include <codecvt>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress-of-packed-member"
namespace base
{
    using namespace CTRPluginFramework;

    struct info
    {
        std::size_t index;
        std::string name;
    };

    void entries::network::mii_dumper_menu(MenuEntry *entry)
    {
        auto keyboard = Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

        auto const &data = (*g_pointers->m_network_engine)->m_network_player_data_manager->m_network_player_datas_connected;

        auto converter = std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>();
        auto const get_name = [&converter](auto const &player_data)
        {
            auto name = std::u16string(reinterpret_cast<char16_t const *>(player_data.m_store_data.mii_data.mii_name), std::size(player_data.m_store_data.mii_data.mii_name));
            name.erase(std::find(name.begin(), name.end(), '\0'), name.end());
            return converter.to_bytes(name);
        };

        auto infos = std::vector<info>();
        for (auto i = std::size_t{}; i < std::size(data); ++i)
            if (data[i].m_loaded)
                infos.push_back({ i, get_name(data[i]) });

        auto options = std::vector<std::string>();
        std::for_each(infos.begin(), infos.end(), [&](auto const &i) { options.push_back(i.name); });

        auto directory = Directory("Miis", true);
        auto file = File();

        while (true)
        {
            keyboard.Populate(options);

            auto const choice = keyboard.Open(); 
            if (choice < 0)
                break;

            auto const &info = infos.at(choice);
            auto const &player_data = data[info.index];

            // Sanitize name just in case
            auto name = get_name(player_data);

        _open:
            auto const path = std::format("{}.3dsmii", name);
            auto const result = directory.OpenFile(file, path, File::WRITE | File::CREATE | File::TRUNCATE | File::SYNC);

            if (result == File::SUCCESS)
            {
                auto const &mii_data = player_data.m_store_data.mii_data;

                if (file.Write(&mii_data, sizeof(mii_data)) == File::SUCCESS && file.Close() == File::SUCCESS)
                {
                    MessageBox(entry->Name(), "Done.")();
                    continue;
                }
            }
            else if (result == File::INVALID_PATH)
            {
                auto const choice = keyboard.Open(name, name);
                if (choice < 0)
                    continue;

                goto _open;
            }

            MessageBox(entry->Name(), "Failed.")();
            break;
        }
    }
}
#pragma GCC diagnostic pop