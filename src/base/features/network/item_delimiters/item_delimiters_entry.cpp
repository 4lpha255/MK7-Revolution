#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/game/item/kart_item.hpp>

namespace base
{
    void features::network::item_delimiters_entry(Item::eItemSlot item, game::item::kart_item *_this)
    {
        if (g_menu->m_item_delimiters_entry->IsActivated())
        {
            switch (item)
            {
            case decltype(item)::Gesso:
            case decltype(item)::Thunder:
                if (g_settings.m_options.network.item_delimiters.items.at(item))
                    _this->m_delimiter_item = item;
                break;
            }
        }
    }
}