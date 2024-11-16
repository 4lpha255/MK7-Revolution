#include <base/entries.hpp>

#include <base/patches.hpp>
#include <base/settings.hpp>

namespace base
{
    void entries::kart::angry_wiggler::game(CTRPluginFramework::MenuEntry *entry)
    {
        if (entry->WasJustActivated())
        {
            g_patches->m_Kart_Driver_calcApply_0x180_patch.enable();

            if (g_settings.m_options.kart.angry_wiggler.keep)
            {
                g_patches->m_Kart_Driver_calcApply_0x1F4_patch.enable();
                g_patches->m_Kart_Driver_calcApply_0x22C_patch.enable();
            }
        }
        else if (!entry->IsActivated())
        {
            g_patches->m_Kart_Driver_calcApply_0x22C_patch.disable();
            g_patches->m_Kart_Driver_calcApply_0x1F4_patch.disable();
            g_patches->m_Kart_Driver_calcApply_0x180_patch.disable();
        }
    }
}