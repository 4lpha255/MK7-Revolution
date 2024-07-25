#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemDirector_entryItem(Item::ItemDirector *_this, Item::eItemSlot item, game::item::kart_item *kart_item)
    {
        features::network::item_delimiters_entry(item, kart_item);

        if (features::item::item_hang_entry(_this, item, kart_item))
            return;

        g_hooking->m_Item_ItemDirector_entryItem_hook.call_original<void>(_this, item, kart_item);
    }
}