#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

namespace base
{
    RaceSys::ERaceRuleMode features::ui::enhanced_minimap::battle_zoom(RaceSys::CRaceInfo *race_info)
    {
        if (g_menu->m_enhanced_minimap_entry->IsActivated())
        {
            auto const &enhanced_minimap = g_settings.m_options.ui.enhanced_minimap;

            switch (enhanced_minimap.battle_zoom)
            {
            case decltype(enhanced_minimap.battle_zoom)::Default:
                break;
            case decltype(enhanced_minimap.battle_zoom)::Enabled:
                return RaceSys::ERaceRuleMode::Battle_3;
            case decltype(enhanced_minimap.battle_zoom)::Disabled:
                return RaceSys::ERaceRuleMode::GrandPrix;
            }
        }

        return race_info->m_race_mode.m_race_rule_mode;
    }
}