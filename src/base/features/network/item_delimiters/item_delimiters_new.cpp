#include <base/features.hpp>

#include <base/game/item/kart_item.hpp>

namespace base
{
    size_t features::network::item_delimiters_new()
    {
        return sizeof(game::item::kart_item);
    }
}