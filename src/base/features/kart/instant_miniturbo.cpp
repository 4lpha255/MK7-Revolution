#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <base/game/kart/unit.hpp>

#include <Kart/Vehicle.hpp>

namespace base
{
	void features::kart::instant_miniturbo(game::kart::unit *_this)
	{
		if (g_menu->m_instant_miniturbo_entry->IsActivated() && _this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
			if (_this->m_vehicle->m_miniturbo_charge > 0)
			{
				auto const &instant_miniturbo = g_settings.m_options.kart.instant_miniturbo;

				switch (instant_miniturbo.type)
				{
					case decltype(instant_miniturbo.type)::Blue: _this->m_vehicle->m_miniturbo_charge = *g_pointers->m_miniturbo_blue_threshold; break;
					case decltype(instant_miniturbo.type)::Red: _this->m_vehicle->m_miniturbo_charge = *g_pointers->m_miniturbo_red_threshold; break;
				}
			}
	}
}