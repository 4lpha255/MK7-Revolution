#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    game::item::kart_item *hooks::Item_KartItem_KartItem(game::item::kart_item *_this, s32 player_id)
    {
        auto const result = g_hooking->m_Item_KartItem_KartItem_hook.call_original<game::item::kart_item *>(_this, player_id);

        features::kart_item_ctor(result);

        return result;
    }
}