#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemObjGesso_stateUse_0x28()
    {
        asm volatile
        (
            "push {lr}\n"
            "mov r0, r4\n"
            "bl __item_selfstrike_gesso\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __item_selfstrike_gesso(Item::ItemObjGesso *_this)
    {
        return features::item::item_selfstrike::gesso(_this);
    }
}