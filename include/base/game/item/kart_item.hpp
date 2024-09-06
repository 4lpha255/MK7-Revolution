#pragma once

#include <Item/KartItem.hpp>

namespace base::game::item
{
    class kart_item : public Item::KartItem
    {
    public:
        struct
        {
            Item::eItemSlot item;
        }
        m_item_delimiters;
        
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
            u32 count;
        }
        m_item_wheel;
    };
    static_assert(sizeof(kart_item) == 0x74);
}