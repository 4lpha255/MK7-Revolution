#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
	void hooks::Kart_Unit_calcMove(game::kart::unit *_this, bool a2, bool a3)
	{
		features::kart::instant_acceleration(_this);
		features::kart::instant_respawn(_this);
		features::kart::instant_miniturbo(_this);
		features::kart::kart_statuses(_this);
		features::mode::stalking(_this);
		features::mode::trigger_respawn(_this);

		g_hooking->m_Kart_Unit_calcMove_hook.call_original<void>(_this, a2, a3);
	}
}