#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::item::disable_item_clear_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

        auto &disable_item_clear = g_settings.m_options.item.disable_item_clear;

		while (true)
		{
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Thunder ({})", menu::s_toggles[disable_item_clear.thunder]),
                std::format("Recover ({})", menu::s_toggles[disable_item_clear.recover]),
            });

			auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: disable_item_clear.thunder ^= true; break;
                case 1: disable_item_clear.recover ^= true; break;
            }
        }
    }
}