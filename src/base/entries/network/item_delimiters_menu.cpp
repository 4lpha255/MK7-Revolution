#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <format>

namespace base
{
    void entries::network::item_delimiters_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

        auto &item_delimiters = g_settings.m_options.network.item_delimiters;

        while (true)
        {
            auto options = std::vector<std::string>();
            std::for_each(item_delimiters.items.begin(), item_delimiters.items.end(), [&](auto const &e) { options.push_back(std::format("{} ({})", utils::item_name(e.first).value_or(std::string(magic_enum::enum_name(e.first))), menu::s_toggles[e.second])); });
            keyboard.Populate(options);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            auto const &item = std::next(item_delimiters.items.begin(), choice);
            item->second ^= true;
        }
    }
}