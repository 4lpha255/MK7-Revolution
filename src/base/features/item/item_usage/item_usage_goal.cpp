#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/Vehicle.hpp>

namespace base
{
    bool features::item::item_usage::goal(Kart::Vehicle *_this)
    {
        using type = settings::options::item::item_usage::type;

        auto is_fake_goal = _this->m_is_fake_goal;

        if (g_menu->m_item_usage_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv)
        {
            if (g_settings.m_options.item.item_usage.toggles.at(type::Goal))
                is_fake_goal = false;
        }

        return is_fake_goal;
    }
}