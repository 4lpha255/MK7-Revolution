#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Item/ItemDirector.hpp>
#include <Item/ItemObj/ItemObjBase.hpp>
#include <Kart/InfoProxy.hpp>

namespace base
{
    void features::item::item_drop(Item::ItemObjBase *_this)
    {
        if (g_menu->m_item_drop_entry->IsActivated() && _this->m_info_proxy->isMaster() && !_this->m_info_proxy->isNetRecv())
        {
            auto const &item_drop = g_settings.m_options.item.item_drop;

            switch (item_drop.mode)
            {
            case decltype(item_drop.mode)::Drop:
                _this->m_is_dropped = true;
                break;
            case decltype(item_drop.mode)::Pop:
                g_pointers->m_Item_ItemDirector_dropEquip(Item::GetDirector(), _this->m_owner_player_id);
                break;
            }
        }
    }
}