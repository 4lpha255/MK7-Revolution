#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::UI_BgRaceZoomMapControl_onCreate_0x20()
    {
        asm volatile
        (
            "push {lr}\n"
            "bl __enhanced_minimap_battle_zoom\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __enhanced_minimap_battle_zoom(RaceSys::CRaceInfo *race_info)
    {
        return features::ui::enhanced_minimap::battle_zoom(race_info);
    }
}