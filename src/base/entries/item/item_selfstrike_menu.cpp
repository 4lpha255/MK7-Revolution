#include <base/entries.hpp>

#include <base/settings.hpp>
#include <base/utils.hpp>

#include <format>

namespace base
{
    void entries::item::item_selfstrike_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

        auto &item_selfstrike = g_settings.m_options.item.item_selfstrike;

        while (true)
        {
            auto options = std::vector<std::string>();
            std::for_each(item_selfstrike.items.begin(), item_selfstrike.items.end(), [&](auto const &i) { options.push_back(std::format("{} ({})", utils::item_name(i.first), magic_enum::enum_name(i.second))); });
            keyboard.Populate(options);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            auto const &item = std::next(item_selfstrike.items.begin(), choice);
            utils::enum_next(item->second);
        }
    }
}