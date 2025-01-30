#include <base/entries.hpp>

#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::ui::grand_prix_timer_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto &grand_prix_timer = g_settings.m_options.ui.grand_prix_timer;

        while (true)
        {
            keyboard.Populate(std::vector<std::string>
            {
                std::format("X ({})", grand_prix_timer.x),
                std::format("Y ({})", grand_prix_timer.y)
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: keyboard.Open(grand_prix_timer.x, grand_prix_timer.x); break;
                case 1: keyboard.Open(grand_prix_timer.y, grand_prix_timer.y); break;
            }
        }
    }
}