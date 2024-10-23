#include <base/features.hpp>

#include <base/menu.hpp>

#include <Item/eItemType.hpp>

#include <map>

namespace base
{
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