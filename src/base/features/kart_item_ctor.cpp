#include <base/features.hpp>

#include <base/game/item/kart_item.hpp>

namespace base
{
    void features::kart_item_ctor(game::item::kart_item *_this)
    {
        _this->m_item_rain.count = 0;
        _this->m_item_rapidfire.count = 0;
        _this->m_item_wheel.index = SIZE_MAX;
        _this->m_item_delimiters.item = Item::eItemSlot::Empty;
    }
}