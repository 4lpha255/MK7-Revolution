#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <format>

namespace base
{
    void entries::item::shell_gravity_modifier_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
        keyboard.DisplayTopScreen = true;

        auto &shell_gravity_modifier = g_settings.m_options.item.shell_gravity_modifier;

        while (true)
        {
            keyboard.GetMessage() = entry->Name();
            
            auto options = std::vector<std::string>();
            options.push_back(std::format("Mode ({})", magic_enum::enum_name(shell_gravity_modifier.mode)));
            if (shell_gravity_modifier.mode == decltype(shell_gravity_modifier.mode)::Custom)
                options.push_back(std::format("Value ({})", shell_gravity_modifier.custom_value));
            options.push_back(std::format("Offset ({}, {})", menu::toggle_name(shell_gravity_modifier.offset.enabled), shell_gravity_modifier.offset.value));
            keyboard.Populate(options);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: utils::enum_next(shell_gravity_modifier.mode); break;
                case 1:
                {
                    if (shell_gravity_modifier.mode == decltype(shell_gravity_modifier.mode)::Custom)
                    {                    
                        keyboard.Open(shell_gravity_modifier.custom_value, shell_gravity_modifier.custom_value);
                        break;
                    }
                    [[fallthrough]];
                }
                case 2:
                {
                    while (true)
                    {
                        keyboard.GetMessage() = entry->Name() + "\nOffset";

                        keyboard.Populate(std::vector<std::string>
                        {
                            std::format("Enabled ({})", menu::toggle_name(shell_gravity_modifier.offset.enabled)),
                            std::format("Value ({})", shell_gravity_modifier.offset.value),
                        });

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: shell_gravity_modifier.offset.enabled ^= true; break;
                            case 1: keyboard.Open(shell_gravity_modifier.offset.value, shell_gravity_modifier.offset.value); break;
                        }
                    }

                    break;
                }
            }
        }
    }
}