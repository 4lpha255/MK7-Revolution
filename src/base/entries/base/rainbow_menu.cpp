#include <base/entries.hpp>

#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::base::rainbow_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(false);

        auto &rainbow = g_settings.m_options.base.rainbow;

        int choice;

        do
        {
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Hue amount: {}", rainbow.hue_amount),
                std::format("Saturation: {}", rainbow.saturation),
                std::format("Value: {}", rainbow.value)
            });

            choice = keyboard.Open();

            switch (choice)
            {
                case 0: keyboard.Open(rainbow.hue_amount, rainbow.hue_amount); break;
                case 1: keyboard.Open(rainbow.saturation, rainbow.saturation); break;
                case 2: keyboard.Open(rainbow.value, rainbow.value); break;
            }
        }
        while (choice >= 0);
    }
}