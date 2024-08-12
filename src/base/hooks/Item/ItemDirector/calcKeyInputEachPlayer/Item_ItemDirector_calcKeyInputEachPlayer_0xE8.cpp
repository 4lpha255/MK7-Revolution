#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemDirector_calcKeyInputEachPlayer_0xE8()
    {
        asm volatile
        (
            "push {lr}\n"
            "mov r0, r5\n"
            "bl __item_rapidfire_execute\n"
            "mov r8, r0\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __item_rapidfire_execute(s32 player_id)
    {
        return features::item::item_rapidfire::execute(player_id);
    }
}