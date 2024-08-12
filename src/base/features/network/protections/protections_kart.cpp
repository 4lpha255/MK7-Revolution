#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/NetData.hpp>

namespace base
{
    bool features::network::protections::kart(Kart::NetData *_this)
    {
        if (g_menu->m_protections_entry->IsActivated())
        {
            auto const &protections = g_settings.m_options.network.protections;

            if (protections.kart.accident_type && _this->m_acd_type >= Kart::VehicleReact::EAcdType::MAX)
                return true;
        }

        return false;
    }
}