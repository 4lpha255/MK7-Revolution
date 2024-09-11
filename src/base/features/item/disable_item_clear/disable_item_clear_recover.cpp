#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Item/ItemDirector.hpp>
#include <Item/KartItem.hpp>

namespace base
{
    bool features::item::disable_item_clear::recover(Item::ItemDirector *_this, s32 player_id)
    {
        return g_menu->m_disable_item_clear_entry->IsActivated() && g_settings.m_options.item.disable_item_clear.recover && _this->m_kart_items.at(player_id)->isMaster() && !_this->m_kart_items.at(player_id)->isNetRecv();
    }
}