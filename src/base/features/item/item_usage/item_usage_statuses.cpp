#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/Vehicle.hpp>

namespace base
{
    Kart::VehicleMove::StatusFlags features::item::item_usage_statuses(Kart::Vehicle *_this)
    {
        using type = settings::options::item::item_usage::type;

        auto status_flags = _this->m_status_flags;

        if (g_menu->m_item_usage_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
        {
            auto const &item_usage = g_settings.m_options.item.item_usage;

            if (item_usage.toggles.at(type::Accident))
                status_flags.accident_1 = false;

            if (item_usage.toggles.at(type::Recover))
                status_flags.jugem_recover = status_flags.jugem_recover_ai = status_flags.battle_restart = false;

            if (item_usage.toggles.at(type::Vanish))
                status_flags.vanish_start = false;

            if (item_usage.toggles.at(type::Killer))
                status_flags.killer = false;
        }

        return status_flags;
    }
}