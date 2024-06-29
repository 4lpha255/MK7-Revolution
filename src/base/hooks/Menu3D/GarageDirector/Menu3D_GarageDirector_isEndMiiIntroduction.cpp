#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    bool hooks::Menu3D_GarageDirector_isEndMiiIntroduction(Menu3D::GarageDirector *_this)
    {
        auto result = features::network::mii_matching_viewer();

        switch (result)
        {
        case decltype(result)::run_original:
            break;
        case decltype(result)::wait_button:
            return false;
        case decltype(result)::skip_mii:
            return true;
        }

        return g_hooking->m_Menu3D_GarageDirector_isEndMiiIntroduction_hook.call_original<bool>(_this);
    }
}