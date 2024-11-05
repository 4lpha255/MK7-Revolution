#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjKouraR_getStripeColor(sead::Color4f *out)
    {
        if (auto const opt = features::item::shell_stripe_color_modifier(Item::eItemType::KouraR); opt.has_value())
        {
            *out = opt.value();
            return;
        }

        g_hooking->m_Item_ItemObjKouraR_hook.get_original<decltype(&Item_ItemObjKouraR_getStripeColor)>(hooks::ItemObjKoura_getStripeColor_index)(out);
    }
}