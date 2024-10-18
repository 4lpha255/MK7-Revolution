#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Item/ItemObj/ItemObjKiller.hpp>
#include <Kart/InfoProxy.hpp>

namespace base
{
    bool features::kart::killer_control::toggle(Item::ItemObjKiller *_this)
    {
        if (g_menu->m_killer_control_entry->IsActivated() && g_settings.m_options.kart.killer_control.toggle)
        {
            if (_this->m_info_proxy->isMaster() && !_this->m_info_proxy->isNetRecv() && _this->m_info_proxy->m_vehicle->m_status_flags.killer)
            {
                g_pointers->m_Kart_VehicleMove_endKiller(_this->m_info_proxy->m_vehicle);
                return true;
            }
        }

        return false;
    }
}