#include <base/features.hpp>

#include <base/pointers.hpp>

#include <base/game/kart/director.hpp>

#include <Kart/Unit.hpp>
#include <Kart/Vehicle.hpp>

namespace base
{
    void features::kart_director_create(game::kart::director *_this)
    {
        auto const capacity = _this->m_units.capacity();
        auto const buffer = g_pointers->m_operator_new(capacity * 4);
        _this->m_opponent_units.setBuffer(capacity, buffer);

        for (auto it = _this->m_units.dataBegin(); it != _this->m_units.dataEnd(); ++it)
            if (!(*it)->m_vehicle->m_is_master || (*it)->m_vehicle->m_is_net_recv)
                _this->m_opponent_units.pushBack(*it);
    }
}