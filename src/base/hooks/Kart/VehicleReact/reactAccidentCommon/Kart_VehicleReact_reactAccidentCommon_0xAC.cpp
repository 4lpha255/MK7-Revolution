#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_VehicleReact_reactAccidentCommon_0xAC()
    {
        asm volatile
        (
            "push {lr}\n"
            "mov r0, r4\n"
            "bl __kart_vulnerabilities_statuses\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __kart_vulnerabilities_statuses(Kart::VehicleReact *_this)
    {
        return features::kart::kart_vulnerabilities::statuses(_this);
    }
}