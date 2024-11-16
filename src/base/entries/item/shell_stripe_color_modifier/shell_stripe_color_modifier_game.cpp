#include <base/entries.hpp>

#include <base/patches.hpp>
#include <base/settings.hpp>

namespace base
{
    void entries::item::shell_stripe_color_modifier_game(CTRPluginFramework::MenuEntry *entry)
    {
        if (entry->WasJustActivated())
        {
            if (g_settings.m_options.item.shell_stripe_color_modifier.keep)
            {
                g_patches->m_Item_ItemObjKouraG_calcStripe_0x34_patch.enable();
                g_patches->m_Item_ItemObjKouraG_calcStripe_0xC4_patch.enable();
            }
        }
        else if (!entry->IsActivated())
        {
            g_patches->m_Item_ItemObjKouraG_calcStripe_0xC4_patch.disable();
            g_patches->m_Item_ItemObjKouraG_calcStripe_0x34_patch.disable();
        }
    }
}