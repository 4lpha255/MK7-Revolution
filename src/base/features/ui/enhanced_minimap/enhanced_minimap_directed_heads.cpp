#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/Vehicle.hpp>
#include <UI/BgRaceMapCharaControl.hpp>

namespace base
{
    bool features::ui::enhanced_minimap::directed_heads(UI::BgRaceMapCharaControl *_this, Kart::Vehicle *vehicle)
    {
        if (g_menu->m_enhanced_minimap_entry->IsActivated() && g_settings.m_options.ui.enhanced_minimap.directed_heads)
            if (!vehicle->m_status_flags.accident_1)
                return true;

        return _this->m_killer_facing;
    }
}