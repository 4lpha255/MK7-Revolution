#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/VehicleReact.hpp>

namespace base
{
    s32 features::kart::kart_vulnerabilities::star(Kart::VehicleReact *_this)
    {
        using status = settings::options::kart::kart_vulnerabilities::status;

        if (g_menu->m_kart_vulnerabilities_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv && g_settings.m_options.kart.kart_vulnerabilities.toggles.at(status::Star))
            return {};

        return _this->m_star_frames;
    }
}