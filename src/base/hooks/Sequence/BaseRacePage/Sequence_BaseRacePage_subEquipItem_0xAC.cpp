#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Sequence_BaseRacePage_subEquipItem_0xAC()
    {
        asm volatile
        (
            "push {r0, lr}\n"
            "mov r0, r4\n"
            "bl __item_hang_icon\n"
            "mov r4, r0\n"
            "pop {r0, pc}\n"
        );
    }

    extern "C" auto __item_hang_icon(Item::eItemType item)
    {
        return features::item::item_hang_icon(item);
    }
}