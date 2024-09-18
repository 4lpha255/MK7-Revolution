#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x78()
    {
        asm volatile
        (
            "push {lr}\n"
            "mov r1, r5\n"
            "bl __item_rapidfire_block\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __item_rapidfire_block(sead::Controller *_this, s32 player_id)
    {
        return features::item::item_rapidfire::block(_this, player_id);
    }
}