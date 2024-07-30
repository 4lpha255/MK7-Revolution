#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Object_CharacterEngine_creators_2_6_0x184()
    {
        asm volatile
        (
            "push {lr}\n"
            "bl __kart_director_size\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __kart_director_size()
    {
        return features::kart_director_size();
    }
}