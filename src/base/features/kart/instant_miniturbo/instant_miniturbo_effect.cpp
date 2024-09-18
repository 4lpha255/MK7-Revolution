#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Kart/VehicleMove.hpp>

namespace base
{
    float features::kart::instant_miniturbo::effect(Kart::VehicleMove *_this)
    {
        if (g_menu->m_instant_miniturbo_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
        {
            auto const &instant_miniturbo = g_settings.m_options.kart.instant_miniturbo;

            if (instant_miniturbo.type == decltype(instant_miniturbo.type)::Red)
                return 0.f;
        }

        return _this->m_miniturbo_charge;
    }
}