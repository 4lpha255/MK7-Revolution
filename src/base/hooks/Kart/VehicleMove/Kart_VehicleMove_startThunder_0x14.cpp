#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_VehicleMove_startThunder_0x14()
    {
        asm volatile
        (
            "push {r0, r2, lr}\n"
            "bl __invincibility_thunder\n"
            "mov r1, r0\n"
            "pop {r0, r2, pc}\n"
        );
    }

    extern "C" auto __invincibility_thunder(Kart::VehicleMove *_this)
    {
        return features::kart::invincibility::press_thunder(_this);
    }
}