#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Sequence_BaseRacePage_subBombBlue_subBombRed_0x4()
    {
        asm volatile
        (
            "push {r0-r1, lr}\n"
            "bl __item_fixes_preview_minimap_explosion\n"
            "cmp r0, #0\n"
            "pop {r0-r1, lr}\n"
            "popne {r4-r8, pc}\n"
            "mov r2, r0\n" // original
            "bx lr\n"
        );
    }

    extern "C" auto __item_fixes_preview_minimap_explosion(Sequence::BaseRacePage *_this)
    {
        return features::item::item_fixes::preview_minimap_explosion(_this);
    }
}