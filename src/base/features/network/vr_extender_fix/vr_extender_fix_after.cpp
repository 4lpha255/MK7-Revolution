#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/patches.hpp>

namespace base
{
    void features::network::vr_extender_fix::after()
    {
        if (g_menu->m_vr_extender_fix_entry->IsActivated())
        {
            g_patches->m_UI_MessageWriter_buildNumString_0x8_patch.disable();
            g_patches->m_UI_MessageWriter_buildNumString_0x11C_patch.disable();
            g_patches->m_UI_MessageWriter_buildNumString_0x124_patch.disable();
        }
    }
}