#include <base/hooking.hpp>
#include <base/features.hpp>

#include <Item/ItemObj/ItemObjGesso.hpp>

namespace base
{
    void hooks::Item_ItemObjGesso_initEntryInnerBefore(Item::ItemObjGesso *_this)
    {
        features::item::item_hang_init(_this);

        g_hooking->m_Item_ItemObjGesso_hook.get_original<decltype(&Item_ItemObjGesso_initEntryInnerBefore)>(hooks::ItemObjBase_initEntryInnerBefore_index)(_this);
    }
}