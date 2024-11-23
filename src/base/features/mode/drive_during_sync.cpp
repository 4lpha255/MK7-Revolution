#include <base/features.hpp>

#include <base/menu.hpp>

#include <RaceSys/ModeManagerBase.hpp>
#include <RaceSys/RaceDirector.hpp>
#include <System/RootSystem.hpp>
#include <System/KDPadInputer.hpp>

namespace base
{
	void features::mode::drive_during_sync::after(RaceSys::ModeManagerBase *mode_manager, RaceSys::ModeManagerBase::RaceState original)
    {
        if (g_menu->m_drive_during_sync_entry->IsActivated())
        {
            if (mode_manager == nullptr)
                mode_manager = System::g_root_system->get_race_director()->m_mode_manager;

            mode_manager->m_race_state = original;
        }
    }

    RaceSys::ModeManagerBase::RaceState features::mode::drive_during_sync::before(RaceSys::ModeManagerBase *mode_manager)
    {
        RaceSys::ModeManagerBase::RaceState original{};

        if (g_menu->m_drive_during_sync_entry->IsActivated())
        {
            if (mode_manager == nullptr)
                mode_manager = System::g_root_system->get_race_director()->m_mode_manager;

            original = mode_manager->m_race_state;
            mode_manager->m_race_state = RaceSys::ModeManagerBase::RaceState_Race;
        }

        return original;
    }

    bool features::mode::drive_during_sync::bottom_screen(bool is_bottom_screen_sync)
    {
        return g_menu->m_drive_during_sync_entry->IsActivated() ? false : is_bottom_screen_sync;
    }

    bool features::mode::drive_during_sync::input(System::KDPadInputer *_this)
    {
        if (g_menu->m_drive_during_sync_entry->IsActivated())
        {
            _this->calcInput();
            return true;
        }

        return false;
    }
}