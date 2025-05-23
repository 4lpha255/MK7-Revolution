#include <base/features.hpp>

#include <base/menu.hpp>

#include <base/game/kart/unit.hpp>

#include <Kart/Vehicle.hpp>

namespace base
{
	void features::kart::instant_respawn(game::kart::unit *_this)
	{
		if (g_menu->m_instant_respawn_entry->IsActivated())
			if (_this->m_vehicle->m_is_master && !_this->m_vehicle->m_is_net_recv)
				if (_this->m_vehicle->m_respawn_frames > c_respawn_threshold)
					_this->m_vehicle->m_respawn_frames = c_respawn_threshold;
	}
}