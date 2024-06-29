#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_GetNumInItemTypeNet_0x8()
    {
        asm volatile
        (
            "push {r1, r2, r4, lr}\n"
            "mov r4, r0\n"
            "bl __force_replacement\n"
            "cmn r0, #1\n"
            "moveq r3, r4\n"
            "mvnne r3, #0\n"
            "pop {r1, r2, r4, pc}\n"
        );
    }

    extern "C" auto __force_replacement(Item::eItemType item)
    {
        return features::network::force_replacement(item);
    }
}