#include <base/features.hpp>

#include <base/menu.hpp>

namespace base
{
    using namespace CTRPluginFramework;
    using result_t = features::network::mii_matching_viewer_result_t;

    result_t features::network::mii_matching_viewer()
    {
        if (g_menu->m_mii_matching_viewer_entry->IsActivated())
            return Controller::IsKeyReleased(Key::A) ? result_t::skip_mii : result_t::wait_button;

        return result_t::run_original;
    }
}