#include <base/features.hpp>

#include <base/game/kart/unit.hpp>

namespace base
{
    void features::kart_unit_ctor(game::kart::unit *_this)
    {
        _this->m_stalking.index = -1;
        _this->m_stalking.changed = false;
    }

    size_t features::kart_unit_size()
    {
        return sizeof(game::kart::unit);
    }
}