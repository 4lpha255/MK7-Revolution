#include <base/features.hpp>

#include <base/menu.hpp>

#include <RaceSys/ModeManagerBase.hpp>
#include <RaceSys/RaceDirector.hpp>
#include <System/RootSystem.hpp>

namespace base
{
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
}