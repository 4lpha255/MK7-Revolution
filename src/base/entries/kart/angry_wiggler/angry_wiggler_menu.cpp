#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/patches.hpp>
#include <base/settings.hpp>

namespace base
{
    void entries::kart::angry_wiggler::menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto &angry_wiggler = g_settings.m_options.kart.angry_wiggler;

        while (true)
        {
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Keep ({})", menu::toggle_name(angry_wiggler.keep)),
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0:
                {
                    angry_wiggler.keep ^= true;
                    g_patches->m_Kart_Driver_calcApply_0x1F4_patch.set(angry_wiggler.keep);
                    g_patches->m_Kart_Driver_calcApply_0x22C_patch.set(angry_wiggler.keep);
                    break;
                }
            }
        }
    }
}