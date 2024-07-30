#include <base/features.hpp>

#include <base/game/kart/unit.hpp>

namespace base
{
    void features::kart_unit_ctor(game::kart::unit *_this)
    {
        _this->m_stalking.index = SIZE_MAX;
    }
}