#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/game/kart/unit.hpp>

#include <Kart/Vehicle.hpp>

namespace base
{

    void features::kart::future_fly::calc(game::kart::unit *_this)
    {
        if (auto const &veh = _this->m_vehicle; g_menu->m_future_fly_entry->IsActivated() && (veh->m_is_master && !veh->m_is_net_recv))
        {
            auto const &future_fly = g_settings.m_options.kart.future_fly;

            veh->m_status_flags.ground_camera = true;

            // Stay frozen in place
            veh->m_forward_speed = 0.f;
            veh->m_velocity = sead::Vector3f::zero;

            // Allow yaw rotation
            veh->m_yaw_strength = veh->m_cpad_x * (!veh->m_controls.accelerate_backwards ? -future_fly.yaw_strength : future_fly.yaw_strength);

            // Allow pitch rotation (limited)
            auto const pitch = veh->m_cpad_y * future_fly.pitch_limit;
            veh->m_front_pitch.x = pitch * veh->m_up.x;
            veh->m_front_pitch.z = pitch * veh->m_up.z;
            
            // Allow movement
            if (veh->m_controls.accelerate_forwards || veh->m_controls.accelerate_backwards)
                *veh->m_position += veh->m_up * (!_this->m_vehicle->m_controls.accelerate_backwards ? future_fly.speed_forward : -future_fly.speed_backward);
        }
    }
}