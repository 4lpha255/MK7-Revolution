#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/NetData.hpp>

namespace base
{
    void features::network::disable_killer_lag(Kart::NetData *_this)
    {
        if (g_menu->m_disable_killer_lag_entry->IsActivated())
            if (_this->m_status_flags.killer)
                _this->m_status_flags.jugem_recover = true;
    }
}