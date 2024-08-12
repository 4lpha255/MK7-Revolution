#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Item/ItemObj/ItemObjStar.hpp>

namespace base
{
    void features::item::item_hang::init(Item::ItemObjBase *_this)
    {
        if (g_menu->m_item_hang_entry->IsActivated() && g_settings.m_options.item.item_hang.items.at(_this->m_item_type))
        {
            _this->m_is_dropped = true;
        }
    }
}