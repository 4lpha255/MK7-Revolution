#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/VehicleReact.hpp>

namespace base
{
    Kart::VehicleMove::StatusFlags features::kart::kart_vulnerabilities::killer(Kart::VehicleReact *_this)
    {
        using status = settings::options::kart::kart_vulnerabilities::status;

        auto status_flags = _this->m_status_flags;

        if (g_menu->m_kart_vulnerabilities_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
        {
            auto const &kart_vulnerabilities = g_settings.m_options.kart.kart_vulnerabilities;

            if (kart_vulnerabilities.toggles.at(status::Killer))
                status_flags.killer = {};
        }

        return status_flags;
    }
}