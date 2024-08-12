#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/VehicleMove.hpp>

namespace base
{
    void features::kart::killer_control::start(Kart::VehicleMove *_this, bool &controllable)
    {
        if (g_menu->m_killer_control_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
            controllable = true;
    }
}