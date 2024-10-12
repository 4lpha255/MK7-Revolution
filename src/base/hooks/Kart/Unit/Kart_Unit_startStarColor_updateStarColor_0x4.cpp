#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_Unit_startStarColor_updateStarColor_0x4()
    {
        asm volatile
        (
            "push {r0, lr}\n"
            "mov r4, r1\n"
            "bl __kart_effect_color_modifier_star\n"
            "cmp r0, #0\n"
            "moveq r1, r4\n"
            "movne r1, r0\n"
            "pop {r0, pc}\n"
        );
    }

    extern "C" auto __kart_effect_color_modifier_star(Kart::Unit *_this)
    {
        return features::kart::kart_effect_color_modifier::star(_this);
    }
}