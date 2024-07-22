#include <base/hooking.hpp>
#include <base/features.hpp>

#include <Item/ItemObj/ItemObjStar.hpp>

namespace base
{
    void hooks::Item_ItemObjStar_initEntryInnerBefore(Item::ItemObjStar *_this)
    {
        features::item::item_hang_init(_this);

        g_hooking->m_Item_ItemObjStar_hook.get_original<decltype(&Item_ItemObjStar_initEntryInnerBefore)>(hooks::ItemObjBase_initEntryInnerBefore)(_this);
    }
}