#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Net_NetworkGameMgr_requestGoal_0x4(Net::NetworkGameMgr *_this, s32 player_id, u32 score, void *self)
    {
        features::network::goal_score_modifier(score);

        g_hooking->m_Net_NetworkGameMgr_requestGoal_0x4_hook.call_original<void>(_this, player_id, score, self);
    }
}