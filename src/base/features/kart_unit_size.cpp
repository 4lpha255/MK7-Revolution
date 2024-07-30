#include <base/features.hpp>

#include <base/game/kart/unit.hpp>

namespace base
{
    size_t features::kart_unit_size()
    {
        return sizeof(game::kart::unit);
    }
}