#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Item/ItemObj/ItemObjKouraR.hpp>

namespace base
{
    bool features::item::item_fixes::blue_shell_battle_respawn(Item::ItemObjKouraR *_this)
    {
        return g_menu->m_item_fixes_entry->IsActivated() && g_settings.m_options.item.item_fixes.blue_shell_battle_respawn && _this->m_item_type == Item::eItemType::KouraB && _this->m_lap_rank_checker == nullptr;
    }
}