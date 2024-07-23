#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/VehicleMove.hpp>

namespace base
{
    void features::kart::killer_control_move(Kart::VehicleMove *_this, float speed)
    {
        if (!g_menu->m_killer_control_entry->IsActivated() || (_this->m_is_master && !_this->m_is_net_recv && !_this->m_status_flags.killer))
            _this->m_forward_speed = speed;
    }
}