#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/services/rainbow_service.hpp>

namespace base
{
    std::optional<sead::Color4f> features::item::shell_stripe_color_modifier(Item::eItemType item)
    {
        if (g_menu->m_shell_stripe_color_modifier_entry->IsActivated())
        {
            auto const &shell = g_settings.m_options.item.shell_stripe_color_modifier.shells.at(item);

            if (shell.enabled)
            {
                switch (shell.mode)
                {
                case decltype(shell.mode)::Custom:
                    return sead::Color4f{ shell.color.r.v, shell.color.g.v, shell.color.b.v, 1.f };
                case decltype(shell.mode)::Rainbow:
                    return g_rainbow_service->get_sead_color();
                default:
                    break;
                }
            }
        }

        return {};
    }
}