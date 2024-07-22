#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_VehicleMove_calcMoveControlCommon_0x7EC()
    {
        asm volatile
        (
            "push {r0, lr}\n"
            "vpush {s0}\n"
            "mov r0, r4\n"
            "vmov s0, s1\n"
            "bl __killer_control_move\n"
            "vpop {s0}\n"
            "pop {r0, pc}\n"
        );
    }

    extern "C" auto __killer_control_move(Kart::VehicleMove *_this, float speed)
    {
        return features::kart::killer_control_move(_this, speed);
    }
}