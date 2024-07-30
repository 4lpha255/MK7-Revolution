#include <base/features.hpp>

#include <base/game/kart/director.hpp>

namespace base
{
    size_t features::kart_director_size()
    {
        return sizeof(game::kart::director);
    }
}