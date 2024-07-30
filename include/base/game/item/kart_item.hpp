#pragma once

#include <Item/KartItem.hpp>

namespace base::game::item
{
    class kart_item : public Item::KartItem
    {
    public:
        struct
        {
            u32 count;
        }
        m_item_rain;

        struct
        {
            u32 count;
        }
        m_item_rapidfire;

        struct
        {
            size_t index;
        }
        m_item_wheel;

        struct
        {
            Item::eItemSlot item;
        }
        m_item_delimiters;
    };
    static_assert(sizeof(kart_item) == 0x70);
}