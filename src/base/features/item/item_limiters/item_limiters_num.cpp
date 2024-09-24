#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

namespace base
{
    std::optional<s32> features::item::item_limiters::num(Item::eItemType item_type)
    {
        if (g_menu->m_item_limiters_entry->IsActivated())
            if (auto const &item_limiters = g_settings.m_options.item.item_limiters; item_limiters.items.contains(item_type) && item_limiters.items.at(item_type).enabled)
                return item_limiters.items.at(item_type).amount;

        return std::nullopt;
    }
}