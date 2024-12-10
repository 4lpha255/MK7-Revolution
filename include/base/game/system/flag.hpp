#pragma once

#include <RaceSys/EGrandPrixID.hpp>

namespace base::game::system
{
    class flag
    {
    public:
        static bool is_default_unlocked(RaceSys::EGrandPrixID);

        static bool get(RaceSys::EGrandPrixID);
        static void set(RaceSys::EGrandPrixID, bool);

        static void toggle(RaceSys::EGrandPrixID);
    };
    static_assert(sizeof(flag) == 0x1);
}