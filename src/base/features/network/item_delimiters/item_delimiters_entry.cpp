#include <base/features.hpp>

#include <base/menu.hpp>

#include <base/game/item/kart_item.hpp>

namespace base
{
    void features::network::item_delimiters_entry(Item::eItemSlot item, game::item::kart_item *_this)
    {
        if (g_menu->m_item_delimiters_entry->IsActivated())
        {
            switch (item)
            {
            case Item::eItemSlot::Gesso:
            case Item::eItemSlot::Thunder:
                _this->m_delimiter_item = item;
                break;
            }
        }
    }
}