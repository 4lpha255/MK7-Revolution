#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    bool hooks::Item_ItemSlot_isStock(Item::ItemSlot *_this)
    {
        if (features::item::item_rapidfire_stock(_this))
            return true;

        return g_hooking->m_Item_ItemSlot_isStock_hook.call_original<bool>(_this);
    }
}