#include <base/features.hpp>

#include <base/game/item/kart_item.hpp>

namespace base
{
    void features::network::item_delimiters_ctor(game::item::kart_item *_this)
    {
        _this->m_delimiter_item = Item::eItemSlot::Empty;
    }
}