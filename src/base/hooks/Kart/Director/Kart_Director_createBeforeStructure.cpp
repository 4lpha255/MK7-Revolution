#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_Director_createBeforeStructure(game::kart::director *_this, void *arg)
    {
        g_hooking->m_Kart_Director_hook.get_original<decltype(&Kart_Director_createBeforeStructure)>(hooks::Director_createBeforeStructure_index)(_this, arg);

        features::kart_director_create(_this);
    }
}