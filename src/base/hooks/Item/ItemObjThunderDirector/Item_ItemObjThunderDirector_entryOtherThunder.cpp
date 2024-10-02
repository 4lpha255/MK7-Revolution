#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjThunderDirector_entryOtherThunder(Item::ItemObjThunderDirector *_this, s32 player_id)
    {
        if (features::item::item_selfstrike::thunder(_this, player_id))
            return;

        g_hooking->m_Item_ItemObjThunderDirector_entryOtherThunder_hook.call_original<void>(_this, player_id);
    }
}