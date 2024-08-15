#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::UI_MessageWriter_buildNumString(UI::MessageWriter *_this, void *a2, u32 vr, u32 a4)
    {
        features::network::vr_extender_fix::before();

        g_hooking->m_UI_MessageWriter_buildNumString_hook.call_original<void>(_this, a2, vr, a4);

        features::network::vr_extender_fix::after();
    }
}