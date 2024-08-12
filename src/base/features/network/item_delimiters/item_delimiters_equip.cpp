#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

#include <base/game/item/kart_item.hpp>

#include <Item/ItemDirector.hpp>
#include <System/RootSystem.hpp>

namespace base
{
    void features::network::item_delimiters::equip(s32 player_id, Item::eItemSlot &item, s32 &amount)
    {
        if (g_menu->m_item_delimiters_entry->IsActivated())
        {
            auto const kart_item = static_cast<game::item::kart_item *>(g_pointers->m_root_system->get_item_director()->m_kart_items.at(player_id));
            
            if (kart_item->m_item_delimiters.item != Item::eItemSlot::Empty)
            {
                item = kart_item->m_item_delimiters.item;
                kart_item->m_item_delimiters.item = Item::eItemSlot::Empty;

                amount = 1;

                // Update the equip (needed for updating server-side)
                kart_item->m_equip_items_used++;
            }
        }
    }
}