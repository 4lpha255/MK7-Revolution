#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_Rigid_updateVel(Kart::Rigid *_this, sead::Vector3f *vel)
    {
        if (features::kart::future_fly::velocity(_this))
            return;

        g_hooking->m_Kart_Rigid_updateVel_hook.call_original<void>(_this, vel);
    }
}