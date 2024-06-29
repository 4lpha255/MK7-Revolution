#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <array>
#include <format>

namespace base
{
    void entries::network::force_replacement_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto const items = std::to_array({ Item::eItemType::KouraG, Item::eItemType::KouraR, Item::eItemType::Banana, Item::eItemType::Kinoko, Item::eItemType::Star, Item::eItemType::KouraB, Item::eItemType::Thunder, Item::eItemType::KinokoP, Item::eItemType::Bomhei, Item::eItemType::Gesso, Item::eItemType::Killer, Item::eItemType::Flower, Item::eItemType::Tail, Item::eItemType::Seven });

        auto &force_replacement = g_settings.m_options.network.force_replacement;

        while (true)
        {
            auto options = std::vector<std::string>();
            std::for_each(items.begin(), items.end(), [&](auto const &i) { options.push_back(std::format("{} ({})", magic_enum::enum_name(i), menu::s_toggles[force_replacement.items.contains(i)])); });
            keyboard.Populate(options);

            int choice;
            if (choice = keyboard.Open(); choice < 0)
                break;

            if (auto const item = items.at(choice); force_replacement.items.contains(item))
                force_replacement.items.erase(item);
            else
                force_replacement.items.emplace(item);
        }
    }
}