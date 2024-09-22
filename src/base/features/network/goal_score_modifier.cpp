#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <RaceSys/RaceInfo/Get.hpp>

namespace base
{
    void features::network::goal_score_modifier(u32 &score)
    {
        if (g_menu->m_goal_score_modifier_entry->IsActivated())
        {
            auto const &goal_score_modifier = g_settings.m_options.network.goal_score_modifier;
            auto const &race_info = RaceSys::GetRaceInfo();

            if (goal_score_modifier.race.enabled)
                // Check taken from Enemy::IsRaceTypeThinkAsRace()
                if (race_info->m_race_mode_flag.race)
                    switch (goal_score_modifier.race.mode)
                    {
                        case decltype(goal_score_modifier.race.mode)::Win: score = {}; break;
                        case decltype(goal_score_modifier.race.mode)::Lose: score = INT32_MAX; break;
                    }

            if (goal_score_modifier.battle.enabled)
                // Check taken from Enemy::IsRaceTypeThinkAsBattle()
                if (race_info->m_race_mode.m_race_rule_mode == RaceSys::ERaceRuleMode::Battle_3 || race_info->m_race_mode.m_race_rule_mode == RaceSys::ERaceRuleMode::Battle_7)
                    switch (goal_score_modifier.battle.mode)
                    {
                        case decltype(goal_score_modifier.battle.mode)::Win: score = INT16_MAX; break;
                        case decltype(goal_score_modifier.battle.mode)::Lose: score = {}; break;
                    }
        }
    }
}