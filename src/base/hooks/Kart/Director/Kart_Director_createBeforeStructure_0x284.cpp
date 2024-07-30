#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_Director_createBeforeStructure_0x284()
    {
        asm volatile
        (
            "push {lr}\n"
            "bl __kart_unit_size\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __kart_unit_size()
    {
        return features::kart_unit_size();
    }
}