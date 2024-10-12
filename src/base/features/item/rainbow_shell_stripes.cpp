#include <base/features.hpp>

#include <base/menu.hpp>

#include <base/services/rainbow_service.hpp>

namespace base
{
    bool features::item::rainbow_shell_stripes(sead::Color4f *out)
    {
        if (g_menu->m_rainbow_shell_stripes_entry->IsActivated())
        {
            auto const color = g_rainbow_service->get_color();
            *out = { color.r.v, color.g.v, color.b.v, 1.f };
            return true;
        }

        return false;
    }
}