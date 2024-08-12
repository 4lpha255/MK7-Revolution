#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjKiller_stateInitUse(Item::ItemObjKiller *_this)
    {
        if (features::kart::killer_control::toggle(_this))
            return;

        g_hooking->m_Item_ItemObjKiller_hook.get_original<decltype(&Item_ItemObjKiller_stateInitUse)>(hooks::ItemObjBase_stateInitUse_index)(_this);
    }
}