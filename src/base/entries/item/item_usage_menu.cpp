#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <format>

namespace base
{
    void entries::item::item_usage_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

        auto &item_usage = g_settings.m_options.item.item_usage;

		while (true)
		{
            auto options = std::vector<std::string>();
            std::for_each(item_usage.toggles.begin(), item_usage.toggles.end(), [&](auto const &e) { options.push_back(std::format("{} ({})", magic_enum::enum_name(e.first), menu::toggle_name(e.second))); });
            keyboard.Populate(options);

			auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            auto const &toggle = std::next(item_usage.toggles.begin(), choice);
            toggle->second ^= true;
        }
    }
}