#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/game/item/kart_item.hpp>

#include <Item/KartItemProxy.hpp>

namespace base
{
    void features::network::item_delimiters::entry(Item::eItemSlot item, game::item::kart_item *_this)
    {
        if (g_menu->m_item_delimiters_entry->IsActivated())
        {
            auto const &item_delimiters = g_settings.m_options.network.item_delimiters;

            if (auto const &e = item_delimiters.items.find(item); e != item_delimiters.items.end() && e->second)
                _this->m_item_delimiters.item = item;
        }
    }

    void features::network::item_delimiters::equip(s32 player_id, Item::eItemSlot &item, s32 &amount)
    {
        if (g_menu->m_item_delimiters_entry->IsActivated())
        {
            auto const &kart_item = static_cast<game::item::kart_item *>(Item::KartItemProxy(player_id).m_kart_item);
            
            if (kart_item->m_item_delimiters.item != Item::eItemSlot::Empty)
            {
                item = kart_item->m_item_delimiters.item;
                kart_item->m_item_delimiters.item = Item::eItemSlot::Empty;

                // Update the equip (needed for updating server-side)
                amount = 1;
                kart_item->m_equip_items_used += amount;
            }
        }
    }
}