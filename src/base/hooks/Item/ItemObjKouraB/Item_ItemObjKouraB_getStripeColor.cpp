#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjKouraB_getStripeColor(sead::Color4f *out)
    {
        if (auto const opt = features::item::shell_stripe_color_modifier(Item::eItemType::KouraB); opt.has_value())
        {
            *out = opt.value();
            return;
        }

        g_hooking->m_Item_ItemObjKouraB_hook.get_original<decltype(&Item_ItemObjKouraB_getStripeColor)>(hooks::ItemObjKoura_getStripeColor_index)(out);
    }
}