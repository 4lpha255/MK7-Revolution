#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

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
            auto const &race_rule_mode = System::g_root_system->get_menu_data()->m_base_race_page->m_race_mode.m_race_rule_mode;

            if (race_rule_mode == RaceSys::ERaceRuleMode::GrandPrix || race_rule_mode == RaceSys::ERaceRuleMode::Versus)
            {
                auto const &grand_prix_timer = g_settings.m_options.ui.grand_prix_timer;
                auto const pane = _this->getRootPane();
                pane->m_translate.x = grand_prix_timer.x;
                pane->m_translate.y = grand_prix_timer.y;
            }
        }
    }

    void features::ui::grand_prix_timer::init(Sequence::RacePage *_this)
    {
        if (g_menu->m_grand_prix_timer_entry->IsActivated())
            g_pointers->m_Sequence_BaseRacePage_initTime(_this);
    }
}