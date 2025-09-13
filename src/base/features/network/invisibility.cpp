#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/NetData.hpp>

#include <limits>

#define MAX std::numeric_limits<s16>::max()

namespace base
{
    void features::network::invisibility(Kart::NetData *_this)
    {
        if (g_menu->m_invisibility_entry->IsActivated())
        {
            auto const &invisibility = g_settings.m_options.network.invisibility;

            switch (invisibility.mode)
            {
            case decltype(invisibility.mode)::Position:
                _this->m_position = sead::Vector3<s16>(MAX, MAX, MAX);
                _this->m_velocity = _this->m_angular_velocity = sead::Vector3<s16>(0, 0, 0);
                _this->m_turning_speed = _this->m_forward_speed = _this->m_drift_steering = _this->m_directional_speed = 0;
                break;
            case decltype(invisibility.mode)::Velocity:
                _this->m_velocity = sead::Vector3<s16>(0, MAX, 0);
                break;
            }
        }
    }
}