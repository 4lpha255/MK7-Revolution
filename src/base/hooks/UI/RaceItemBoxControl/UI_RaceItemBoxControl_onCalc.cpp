#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::UI_RaceItemBoxControl_onCalc_0x23C()
    {
        asm volatile
        (
            "push {r0, lr}\n"
            "ldr r0, [r4, #0x9c]\n"
            "bl __item_wheel_anim\n"
            "mov r1, r0\n"
            "pop {r0, pc}\n"
        );
    }

    extern "C" auto __item_wheel_anim(Item::KartItemProxy *kart_item_proxy)
    {
        return features::item::item_wheel::anim(kart_item_proxy);
    }

    void hooks::UI_RaceItemBoxControl_onCalc_0x254()
    {
        asm volatile
        (
            "push {lr}\n"
            "ldr r1, [r4, #0x9c]\n"
            "bl __item_wheel_sound\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __item_wheel_sound(RaceSys::CRaceInfo *race_info, Item::KartItemProxy *kart_item_proxy)
    {
        return features::item::item_wheel::sound(race_info, kart_item_proxy);
    }
}