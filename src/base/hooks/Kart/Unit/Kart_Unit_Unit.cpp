#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    game::kart::unit *hooks::Kart_Unit_Unit(game::kart::unit *_this, s32 player_id, RaceSys::CRaceInfo *race_info, bool is_detail)
    {
        auto const result = g_hooking->m_Kart_Unit_Unit_hook.call_original<game::kart::unit *>(_this, player_id, race_info, is_detail);

        features::kart_unit_ctor(result);

        return result;
    }
}