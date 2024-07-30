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
            auto const &item_delimiters = g_settings.m_options.network.item_delimiters;

            if (auto const &e = item_delimiters.items.find(item); e != item_delimiters.items.end() && e->second)
                _this->m_item_delimiters.item = item;
        }
    }
}