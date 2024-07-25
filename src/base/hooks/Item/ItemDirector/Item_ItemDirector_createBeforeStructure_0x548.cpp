#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemDirector_createBeforeStructure_0x548()
    {
        asm volatile
        (
            "push {lr}\n"
            "bl __item_delimiters_new\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __item_delimiters_new()
    {
        return features::network::item_delimiters_new();
    }
}