#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_VehicleMove_startPress_0x20()
    {
        asm volatile
        (
            "push {r2, lr}\n"
            "mov r0, r4\n"
            "bl __invincibility_press\n"
            "pop {r2, pc}\n"
        );
    }

    extern "C" auto __invincibility_press(Kart::VehicleMove *_this)
    {
        return features::kart::invincibility::press_thunder(_this);
    }
}