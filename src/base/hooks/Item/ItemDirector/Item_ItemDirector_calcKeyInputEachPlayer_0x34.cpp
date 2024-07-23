#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x34()
    {
        asm volatile
        (
            "push {r0, lr}\n"
            "bl __item_usage\n"
            "mov r1, r0\n"
            "pop {r0, pc}\n"
        );
    }

    extern "C" auto __item_usage(Kart::Vehicle *_this)
    {
        return features::item::item_usage(_this);
    }
}