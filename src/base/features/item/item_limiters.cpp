#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

namespace base
{
    std::optional<s32> features::item::item_limiters::extra_num(Item::eItemType item_type)
    {
        if (g_menu->m_item_limiters_entry->IsActivated())
            if (auto const &item_limiters = g_settings.m_options.item.item_limiters; item_limiters.items.contains(item_type) && item_limiters.items.at(item_type).enabled)
                return 0;

        return std::nullopt;
    }

    std::optional<s32> features::item::item_limiters::num(Item::eItemType item_type)
    {
        if (g_menu->m_item_limiters_entry->IsActivated())
            if (auto const &item_limiters = g_settings.m_options.item.item_limiters; item_limiters.items.contains(item_type) && item_limiters.items.at(item_type).enabled)
                return item_limiters.items.at(item_type).amount;

        return std::nullopt;
    }

    void features::item::item_limiters::stripes(s32 &max)
    {
        if (g_menu->m_item_limiters_entry->IsActivated())
        {
            // Calculate the amount of stripes to allocate (limited and original); original amount is hardcoded and based on EItemPattern.
            auto const is_shell_pattern = max == 47;
            auto const data = std::map<Item::eItemType, s32>
            {
                { Item::eItemType::KouraG, is_shell_pattern ? 23 : 11 },
                { Item::eItemType::KouraR, is_shell_pattern ? 23 : 11 },
                { Item::eItemType::KouraB, 1 },
            };

            max = 0;
            for (auto const &[item_type, amount] : data)
                max += num(item_type).value_or(amount);
        }
    }
}