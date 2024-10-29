#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Sequence_MenuMultiCourseVote_onPagePreStep_0x344()
    {
        asm volatile
        (
            "push {lr}\n"
            "mov r0, r4\n"
            "mov r1, r8\n"
            "sub r2, r7, #0x268\n"
            "bl __course_vote_controller\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __course_vote_controller(Sequence::MenuData *data, Net::NetworkSelectMenuProcess *process, Net::NetworkEngine *engine)
    {
        return features::network::course_vote_controller(data, process, engine);
    }
}