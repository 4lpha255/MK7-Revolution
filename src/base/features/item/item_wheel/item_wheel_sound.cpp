#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/game/item/kart_item.hpp>

#include <Item/KartItemProxy.hpp>

namespace base
{
    RaceSys::ERaceRuleMode features::item::item_wheel::sound(RaceSys::CRaceInfo *race_info, Item::KartItemProxy *kart_item_proxy)
    {
        if (g_menu->m_item_wheel_entry->IsActivated() && static_cast<game::item::kart_item *>(kart_item_proxy->m_kart_item)->m_item_wheel.index != SIZE_MAX)
        {
            auto const &item_wheel = g_settings.m_options.item.item_wheel;

            switch (item_wheel.decide_sound)
            {
            case decltype(item_wheel.decide_sound)::Default:
                break;
            case decltype(item_wheel.decide_sound)::Enabled:
                return RaceSys::ERaceRuleMode::GrandPrix;
            case decltype(item_wheel.decide_sound)::Disabled:
                return RaceSys::ERaceRuleMode::TimeTrials;
            }
        }

        return race_info->m_race_mode.m_race_rule_mode;
    }
}