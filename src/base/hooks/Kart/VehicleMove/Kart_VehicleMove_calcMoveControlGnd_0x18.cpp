#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_VehicleMove_calcMoveControlGnd_0x18()
    {
        asm volatile
        (
            "push {lr}\n"
            "bl __kart_usage\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __kart_usage(Kart::Vehicle *_this)
    {
        return features::kart::kart_usage(_this);
    }
}