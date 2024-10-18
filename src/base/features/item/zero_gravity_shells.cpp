#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Item/ItemObj/ItemObjKouraG.hpp>
#include <Kart/InfoProxy.hpp>

namespace base
{
    void features::item::zero_gravity_shells(Item::ItemObjKouraG *_this)
    {
        if (g_menu->m_zero_gravity_shells_entry->IsActivated() && !_this->m_info_proxy->isNetRecv())
        {
            _this->m_gravity = 0;

            if (g_settings.m_options.item.zero_gravity_shells.offset.enabled)
                _this->m_position.y += g_settings.m_options.item.zero_gravity_shells.offset.value;
        }
    }
}