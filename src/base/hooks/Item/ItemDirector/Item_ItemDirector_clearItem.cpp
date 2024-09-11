#include <base/hooking.hpp>
#include <base/features.hpp>
#include <base/pointers.hpp>

namespace base
{
    void hooks::Item_ItemDirector_clearItem(Item::ItemDirector *_this, s32 player_id)
    {
        auto const return_address = __builtin_return_address(0);
        if (return_address == g_pointers->m_Item_ItemObjThunder_stateInitAttacked_0x17C)
        {
            if (features::item::disable_item_clear::thunder(_this, player_id))
                return;
        }
        else if (return_address == g_pointers->m_Kart_Unit_startJugemRecover_0x60)
        {
            if (features::item::disable_item_clear::recover(_this, player_id))
                return;
        }

        g_hooking->m_Item_ItemDirector_clearItem_hook.call_original<void>(_this, player_id);
    }
}