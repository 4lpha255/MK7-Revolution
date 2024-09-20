#include <base/features.hpp>

#include <base/menu.hpp>

namespace base
{
    bool features::kart::future_fly::velocity(Kart::Rigid *_this)
    {
        // TODO: unsafe as it invalidates the inheritance chain, but bail with it
        auto const vehicle = reinterpret_cast<Kart::VehicleBase *>(_this);

        return g_menu->m_future_fly_entry->IsActivated() && vehicle->m_is_master && !vehicle->m_is_net_recv;
    }
}