#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_VehicleMove_isMiniTurboOverLv1_0x8()
    {
        asm volatile
        (
            "push {lr}\n"
            "sub r0, #0xc00\n"
            "bl __instant_miniturbo_effect\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __instant_miniturbo_effect(Kart::VehicleMove *_this)
    {
        return features::kart::instant_miniturbo::effect(_this);
    }
}