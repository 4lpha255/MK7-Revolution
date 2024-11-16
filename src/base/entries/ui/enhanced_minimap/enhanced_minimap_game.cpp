#include <base/entries.hpp>

#include <base/patches.hpp>
#include <base/settings.hpp>

namespace base
{
    void entries::ui::enhanced_minimap::game(CTRPluginFramework::MenuEntry *entry)
    {
        if (entry->WasJustActivated())
        {
            if (g_settings.m_options.ui.enhanced_minimap.extended_minimap_items)
            {
                g_patches->m_Sequence_BaseRacePage_drawItemIcon_0x44_patch.enable();
                g_patches->m_Sequence_BaseRacePage_drawItemIcon_0x28C_patch.enable();
            }
        }
        else if (!entry->IsActivated())
        {
            g_patches->m_Sequence_BaseRacePage_drawItemIcon_0x28C_patch.disable();
            g_patches->m_Sequence_BaseRacePage_drawItemIcon_0x44_patch.disable();
        }
    }
}