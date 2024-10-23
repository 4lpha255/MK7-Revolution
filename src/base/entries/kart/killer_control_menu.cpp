#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::kart::killer_control_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

        auto &killer_control = g_settings.m_options.kart.killer_control;

        while (true)
        {
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Toggle ({})", menu::toggle_name(killer_control.toggle))
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: killer_control.toggle ^= true; break;
            }
        }
    }
}