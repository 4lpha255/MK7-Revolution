#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::UI_TimeControl_onCreate(UI::TimeControl *_this, UI::Control::CreateArg *arg)
    {
        features::ui::grand_prix_timer::create(_this);

        g_hooking->m_UI_TimeControl_hook.get_original<decltype(&UI_TimeControl_onCreate)>(hooks::UI_Control_onCreate_index)(_this, arg);
    }
}