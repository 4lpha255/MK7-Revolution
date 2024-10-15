#include <base/features.hpp>

#include <base/menu.hpp>

namespace base
{
    s32 features::kart::invincibility::press_thunder(Kart::VehicleMove *_this)
    {
        if (g_menu->m_invincibility_entry->IsActivated() && _this->m_is_master)
            return 1;

        return _this->m_star_frames;
    }
}