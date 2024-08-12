#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/Vehicle.hpp>

namespace base
{
    s32 features::item::item_usage::dokan(Kart::Vehicle *_this)
    {
        using type = settings::options::item::item_usage::type;

        auto dokan_warp = _this->m_dokan_warp;

        if (g_menu->m_item_usage_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
        {
            if (g_settings.m_options.item.item_usage.toggles.at(type::Dokan))
                dokan_warp = 0xFF;
        }

        return dokan_warp;
    }
}