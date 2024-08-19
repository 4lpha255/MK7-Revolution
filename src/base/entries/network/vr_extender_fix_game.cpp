#include <base/entries.hpp>

#include <base/patches.hpp>

namespace base
{
    void entries::network::vr_extender_fix_game(CTRPluginFramework::MenuEntry *entry)
    {
        if (entry->WasJustActivated())
        {
            g_patches->m_UI_MessageWriter_buildNumString_0x8_patch.enable();
            g_patches->m_UI_MessageWriter_buildNumString_0x11C_patch.enable();
            g_patches->m_UI_MessageWriter_buildNumString_0x124_patch.enable();
        }
        else if (!entry->IsActivated())
        {
            g_patches->m_UI_MessageWriter_buildNumString_0x8_patch.disable();
            g_patches->m_UI_MessageWriter_buildNumString_0x11C_patch.disable();
            g_patches->m_UI_MessageWriter_buildNumString_0x124_patch.disable();
        }
    }
}