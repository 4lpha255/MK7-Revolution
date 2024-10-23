#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::item::zero_gravity_shells_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
        keyboard.DisplayTopScreen = true;

        auto &zero_gravity_shells = g_settings.m_options.item.zero_gravity_shells;

        while (true)
        {
            keyboard.GetMessage() = entry->Name();
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Offset ({}, {})", menu::toggle_name(zero_gravity_shells.offset.enabled), zero_gravity_shells.offset.value)
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: 
                {
                    auto &offset = zero_gravity_shells.offset;

                    while (true)
                    {
                        keyboard.GetMessage() = entry->Name() + "\nOffset";
                        keyboard.Populate(std::vector<std::string>
                        {
                            std::format("Enabled ({})", menu::toggle_name(zero_gravity_shells.offset.enabled)),
                            std::format("Value ({})", zero_gravity_shells.offset.value),
                        });

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: offset.enabled ^= true; break;
                            case 1: keyboard.Open(offset.value, offset.value); break;
                        }
                    }

                    break;
                }
            }
        }
    }
}