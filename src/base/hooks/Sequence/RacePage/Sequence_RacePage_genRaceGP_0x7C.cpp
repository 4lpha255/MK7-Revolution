#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Sequence_RacePage_genRaceGP_0x7C()
    {
        asm volatile
        (
            "push {lr}\n"
            "mov r0, r5\n"
            "bl __grand_prix_timer_init\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __grand_prix_timer_init(Sequence::RacePage *_this)
    {
        return features::ui::grand_prix_timer::init(_this);
    }
}