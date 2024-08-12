#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Kart_VehicleMove_startKillerImpl(Kart::VehicleMove *_this, bool controllable)
    {
        features::kart::killer_control::start(_this, controllable);

        g_hooking->m_Kart_VehicleMove_startKillerImpl_hook.call_original<void>(_this, controllable);
    }
}