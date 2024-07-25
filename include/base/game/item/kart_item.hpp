#pragma once

#include <Item/KartItem.hpp>

namespace base::game::item
{
    class kart_item : public Item::KartItem
    {
    public:
        Item::eItemSlot m_delimiter_item;
    };
    static_assert(sizeof(kart_item) == 0x64);
}