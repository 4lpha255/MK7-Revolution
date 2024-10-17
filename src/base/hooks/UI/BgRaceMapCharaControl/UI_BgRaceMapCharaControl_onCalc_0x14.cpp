#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::UI_BgRaceMapCharaControl_onCalc_0x14()
    {
        asm volatile
        (
            "push {r0, lr}\n"
            "mov r1, r5\n"
            "bl __enhanced_minimap\n"
            "mov r1, r0\n"
            "pop {r0, pc}\n"
        );
    }

    extern "C" auto __enhanced_minimap(UI::BgRaceMapCharaControl *_this, Kart::Vehicle *vehicle)
    {
        return features::ui::enhanced_minimap::directed_heads(_this, vehicle);
    }
}