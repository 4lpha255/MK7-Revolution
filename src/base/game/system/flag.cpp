#include <base/game/system/flag.hpp>

#include <base/pointers.hpp>

#include <types.h>

#include <System/SystemSaveData.hpp>

#define DEFAULT_FLAG -1

namespace base::game::system
{
    bool flag::is_default_unlocked(RaceSys::EGrandPrixID id)
    {
        return g_pointers->m_grand_prix_flags[id] == DEFAULT_FLAG;
    }

    bool flag::get(RaceSys::EGrandPrixID id)
    {
        if (id == RaceSys::EGrandPrixID_INVALID || g_pointers->m_system_save_data == nullptr)
            return false;

        if (is_default_unlocked(id))
            return true;

        return g_pointers->m_system_save_data->m_player_flag_save_data.m_flag_data.gp_vr.get_gp() & BIT(g_pointers->m_grand_prix_flags[id]);
    }

    void flag::set(RaceSys::EGrandPrixID id, bool status)
    {
        if (id == RaceSys::EGrandPrixID_INVALID || g_pointers->m_system_save_data == nullptr || is_default_unlocked(id))
            return;

        auto &gp_vr = g_pointers->m_system_save_data->m_player_flag_save_data.m_flag_data.gp_vr;
        auto gp = gp_vr.get_gp();

        auto const bit = BIT(g_pointers->m_grand_prix_flags[id]);

        if (status)
            gp |= bit;
        else
            gp &= ~bit;
        gp_vr.set_gp(gp);
    }

    void flag::toggle(RaceSys::EGrandPrixID id)
    {
        set(id, !get(id));
    }
}