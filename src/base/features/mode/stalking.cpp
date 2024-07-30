#include <base/features.hpp>

#include <base/menu.hpp>

#include <base/game/kart/director.hpp>
#include <base/game/kart/unit.hpp>

#include <Kart/Vehicle.hpp>

namespace base
{
    void features::mode::stalking(game::kart::unit *_this)
    {
        using namespace CTRPluginFramework;

        if (g_menu->m_stalking_entry->IsActivated() && _this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
        {
            auto const &units = static_cast<game::kart::director *>(_this->m_vehicle->m_director)->m_opponent_units;

            if (!units.isEmpty())
            {
                if (Controller::IsKeyDown(Key::R))
                {
                    if (Controller::IsKeyPressed(Key::DPadLeft))
                        _this->m_stalking.index = (_this->m_stalking.index == SIZE_MAX ? units.size() - 1 : _this->m_stalking.index - 1);
                    if (Controller::IsKeyPressed(Key::DPadRight))
                        _this->m_stalking.index = (_this->m_stalking.index == units.size() - 1 ? SIZE_MAX : _this->m_stalking.index + 1);
                    if (Controller::IsKeyPressed(Key::DPadDown))
                        _this->m_stalking.index = SIZE_MAX;
                }

                if (_this->m_stalking.index != SIZE_MAX)
                {
                    auto const &unit = units.at(_this->m_stalking.index);

                    *_this->m_vehicle->m_angle = *unit->m_vehicle->m_angle;
                    *_this->m_vehicle->m_position = *unit->m_vehicle->m_position;
                }
            }
        }
    }
}