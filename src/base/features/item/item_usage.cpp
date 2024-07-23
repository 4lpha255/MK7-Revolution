#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/Vehicle.hpp>

namespace base
{
    Kart::VehicleMove::StatusFlags features::item::item_usage(Kart::Vehicle *_this)
    {
        using type_t = settings::options::item::item_usage::type;

        auto status_flags = _this->m_status_flags;

        if (g_menu->m_item_usage_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
        {
            if (g_settings.m_options.item.item_usage.toggles.at(type_t::Accident))
                status_flags.accident_1 = false;

            if (g_settings.m_options.item.item_usage.toggles.at(type_t::Recover))
                status_flags.jugem_recover = status_flags.jugem_recover_ai = status_flags.battle_restart = false;

            if (g_settings.m_options.item.item_usage.toggles.at(type_t::Killer))
                status_flags.killer = false;
        }

        return status_flags;
    }
}