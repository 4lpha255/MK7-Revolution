#include <base/entries.hpp>

#include <base/pointers.hpp>

#include <base/services/message_service.hpp>

#include <System/GameSetting.hpp>
#include <System/RootSystem.hpp>
#include <System/SystemSaveData.hpp>

#include <map>
#include <set>

struct entry_t
{
    u32 id;
    std::string name;

    bool operator<(entry_t const &other) const { return name < other.name; }
};

using entry_set_t = std::set<entry_t>;
using entry_map_t = std::map<entry_t, entry_set_t>;

namespace base
{
    entry_map_t load_map();

    void entries::system::save_data_modifier_game(CTRPluginFramework::MenuEntry *entry)
    {
        if (g_pointers->m_system_save_data == nullptr)
            return;

        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(false);

        auto &data = g_pointers->m_system_save_data->m_player_flag_save_data;
        auto const game_setting = System::g_root_system->get_game_setting();

        while (true)
        {
        _main:
            keyboard.Populate(std::vector<std::string>
            {
                std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::VR), data.m_flag_data.gp_vr.get_vr()),
                std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::Wins), data.m_flag_data.wins),
                std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::Losses), data.m_flag_data.losses),
                std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::CoinsCollected), data.m_flag_data.coins),
                std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::StreetPassTags), data.m_flag_data.streetpass_tags),
                g_message_service->get("Menu", LMS_MessageID::Region),
                std::format("Globe ({}, {})", game_setting->m_globe_position.x, game_setting->m_globe_position.y),
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0:
                {
                    auto vr = data.m_flag_data.gp_vr.get_vr();
                    if (keyboard.Open(vr, vr) == 0)
                        data.m_flag_data.gp_vr.set_vr(vr);
                    break;
                }
                case 1: keyboard.Open(data.m_flag_data.wins, data.m_flag_data.wins); break;
                case 2: keyboard.Open(data.m_flag_data.losses, data.m_flag_data.losses); break;
                case 3: keyboard.Open(data.m_flag_data.coins, data.m_flag_data.coins); break;
                case 4: keyboard.Open(data.m_flag_data.streetpass_tags, data.m_flag_data.streetpass_tags); break;
                case 5:
                {
                    auto const map = load_map();

                    while (true)
                    {
                        auto options = std::vector<std::string>();
                        std::for_each(map.begin(), map.end(), [&](auto const &c) { options.push_back(c.first.name); });
                        keyboard.Populate(options);

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        auto const &country = std::next(map.begin(), choice);
                        
                        while (true)
                        {
                            auto options = std::vector<std::string>();
                            std::for_each(country->second.begin(), country->second.end(), [&](auto const &o) { options.push_back(o.name); });
                            keyboard.Populate(options);

                            auto const choice = keyboard.Open();
                            if (choice < 0)
                                break;

                            auto const &other = std::next(country->second.begin(), choice);

                            game_setting->m_country_id = country->first.id;
                            game_setting->m_region_id = other->id;
                            goto _main;
                        }
                    }

                    break;
                }
                case 6:
                {
                    while (true)
                    {
                        keyboard.Populate(std::vector<std::string>
                        {
                            std::format("X ({})", game_setting->m_globe_position.x),
                            std::format("Y ({})", game_setting->m_globe_position.y),
                        });

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: keyboard.Open(game_setting->m_globe_position.x, game_setting->m_globe_position.x); break;
                            case 1: keyboard.Open(game_setting->m_globe_position.y, game_setting->m_globe_position.y); break;
                        }
                    }
                    
                    break;
                }
            }
        }
    }

    entry_map_t load_map()
    {
        auto map = entry_map_t();

        auto constexpr country_offset = LMS_MessageID::Region_begin - LMS_MessageID::Region_region;
        auto constexpr other_offset = LMS_MessageID::Japan - LMS_MessageID::Region_begin;

        auto constexpr begin_index = other_offset;
        auto constexpr end_index = ((LMS_MessageID::VaticanCity - LMS_MessageID::Japan) / country_offset) + (LMS_MessageID::Region_end - LMS_MessageID::VaticanCity);

        auto const get_country_id = [](auto const index) { return static_cast<LMS_MessageID>(LMS_MessageID::Region_region + (index * country_offset) + other_offset); };
        auto const get_other_id = [](auto const country_id, auto const index) { return static_cast<LMS_MessageID>(country_id + index - other_offset); };

        auto const get_message = [](auto const id) { return g_message_service->get("Region", static_cast<LMS_MessageID>(id)); };

        for (auto i = begin_index; i <= end_index; i += other_offset)
        {
            auto const country_id = get_country_id(i);
            auto const country = get_message(country_id);
            if (country.empty())
                continue;

            auto const country_entry = entry_t{ i, country };
            map.emplace(country_entry, entry_set_t{});
            map.at(country_entry).emplace(0, "(None)");

            for (auto j = begin_index + other_offset; j < country_offset; j += other_offset)
            {
                auto const other_id = get_other_id(country_id, j);
                auto const other = get_message(other_id);
                if (other.empty())
                    continue;

                auto const other_entry = entry_t{ j, other };
                map.at(country_entry).emplace(other_entry);
            }
        }

        return map;
    }
}