#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemDirector_createBeforeStructure_0x548()
    {
        asm volatile
        (
            "push {lr}\n"
            "bl __kart_item_size\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __kart_item_size()
    {
        return features::kart_item_size();
    }
}