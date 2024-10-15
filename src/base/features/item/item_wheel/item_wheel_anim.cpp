#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/game/item/kart_item.hpp>

#include <Item/KartItemProxy.hpp>

#define ANIM_RECEIVE 1
#define ANIM_USE 2

namespace base
{
    s32 features::item::item_wheel::anim(Item::KartItemProxy *kart_item_proxy)
    {
        if (g_menu->m_item_wheel_entry->IsActivated() && static_cast<game::item::kart_item *>(kart_item_proxy->m_kart_item)->m_item_wheel.index != SIZE_MAX)
        {
            auto const &item_wheel = g_settings.m_options.item.item_wheel;

            switch (item_wheel.decide_anim)
            {
            case decltype(item_wheel.decide_anim)::Default:
                break;
            case decltype(item_wheel.decide_anim)::Use:
                return ANIM_USE;
            }
        }

        return ANIM_RECEIVE;
    }
}