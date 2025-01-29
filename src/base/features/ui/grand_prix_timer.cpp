#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>

#include <Sequence/MenuData.hpp>
#include <Sequence/RacePage.hpp>
#include <System/RootSystem.hpp>
#include <UI/TimeControl.hpp>

namespace base
{
    void features::ui::grand_prix_timer::create(UI::TimeControl *_this)
    {
        if (g_menu->m_grand_prix_timer_entry->IsActivated())
        {
            auto const &mode = System::g_root_system->get_menu_data()->m_base_race_page->m_mode;
            if (mode == 0 || mode == 2) // GrandPrix offline and online
            {
                auto const pane = _this->getRootPane();
                pane->m_translate.x = -275.f;
                pane->m_translate.y = -205.f;
            }
        }
    }

    void features::ui::grand_prix_timer::init(Sequence::RacePage *_this)
    {
        if (g_menu->m_grand_prix_timer_entry->IsActivated())
            g_pointers->m_Sequence_BaseRacePage_initTime(_this);
    }
}