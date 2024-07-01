#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjKouraG_getStripeColor(sead::Color4f *out)
    {
        if (features::item::rainbow_shell_stripes(out))
            return;

        g_hooking->m_Item_ItemObjKouraG_hook.get_original<decltype(&Item_ItemObjKouraG_getStripeColor)>(hooks::ItemObjKoura_getStripeColor_index)(out);
    }
}