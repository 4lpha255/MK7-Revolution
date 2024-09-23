#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

namespace base
{
    std::optional<s32> features::network::force_replacement(Item::eItemType item)
    {
        if (g_menu->m_force_replacement_entry->IsActivated() && g_settings.m_options.network.force_replacement.items.contains(item))
            return std::numeric_limits<s32>::min();

        return {};
    }
}