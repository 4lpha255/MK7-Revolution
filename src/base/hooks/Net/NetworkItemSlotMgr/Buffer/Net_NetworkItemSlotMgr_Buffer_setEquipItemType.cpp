#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Net_NetworkItemSlotMgr_Buffer_setEquipItemType(Net::NetworkItemSlotMgr::Buffer *_this, s32 player_id, Item::eItemSlot item, s32 amount)
    {
        features::network::item_delimiters::equip(player_id, item, amount);

        g_hooking->m_Net_NetworkItemSlotMgr_Buffer_setEquipItemType_hook.call_original<void>(_this, player_id, item, amount);
    }
}