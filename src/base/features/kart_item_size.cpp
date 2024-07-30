#include <base/features.hpp>

#include <base/game/item/kart_item.hpp>

namespace base
{
    size_t features::kart_item_size()
    {
        return sizeof(game::item::kart_item);
    }
}