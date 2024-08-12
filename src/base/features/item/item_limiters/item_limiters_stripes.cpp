#include <base/features.hpp>

#include <base/menu.hpp>

#include <Item/eItemType.hpp>

namespace base
{
    void features::item::item_limiters::stripes(s32 &max)
    {
        if (g_menu->m_item_limiters_entry->IsActivated())
        {
            // Calculate the amount of stripes to allocate (limited and original); original amount is hardcoded and based on EItemPattern.
            auto const is_shells_mode = max == 47;
            auto const data = std::map<Item::eItemType, s32>
            {
                { Item::eItemType::KouraG, is_shells_mode ? 23 : 11 },
                { Item::eItemType::KouraR, is_shells_mode ? 23 : 11 },
                { Item::eItemType::KouraB, 1 },
            };

            auto result = s32{};

            for (auto const &e : data)
                if (auto const amount = num(e.first); amount != -1)
                    result += amount;
                else
                    result += e.second;

            if (result != 0)
                max = result;
        }
    }
}