#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <format>

namespace base
{
    void entries::item::item_hang_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;
        
        auto &item_hang = g_settings.m_options.item.item_hang;

        while (true)
		{
            auto options = std::vector<std::string>();
            std::for_each(item_hang.items.begin(), item_hang.items.end(), [&](auto const &i) { options.push_back(std::format("{} ({})", utils::item_name(i.first).value_or(std::string(magic_enum::enum_name(i.first))), menu::toggle_name(i.second))); });
            keyboard.Populate(options);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            auto const &item = std::next(item_hang.items.begin(), choice);
            item->second ^= true;
        }
    }
}