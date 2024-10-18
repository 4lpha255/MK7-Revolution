#include <base/features.hpp>

#include <base/menu.hpp>

#include <Item/ItemSlot.hpp>
#include <Kart/InfoProxy.hpp>

namespace base
{
    bool features::item::item_rapidfire::stock(Item::ItemSlot *_this)
    {
        return g_menu->m_item_rapidfire_entry->IsActivated() && _this->m_info_proxy->isMaster() && !_this->m_info_proxy->isNetRecv() && _this->m_state_observer.m_status_current == Item::ItemSlot::ObserverStatus_Stock;
    }
}