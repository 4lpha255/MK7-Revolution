#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Item/ItemDirector.hpp>
#include <Item/ItemObjDirector/ItemObjThunderDirector.hpp>
#include <Item/KartItem.hpp>

namespace base
{
    bool features::item::item_selfstrike::thunder(Item::ItemObjThunderDirector *_this, s32 player_id)
    {
        if (g_menu->m_item_selfstrike_entry->IsActivated())
        {
            auto const &kart_item = static_cast<Item::ItemDirector *>(_this->m_parent)->m_kart_items.at(player_id);

            if (kart_item->isMaster() && !kart_item->isNetRecv())
            {
                auto const mode = g_settings.m_options.item.item_selfstrike.items.at(Item::eItemType::Thunder);
                auto const use = [&]() { g_pointers->m_Item_ItemObjDirectorBase_entryUse(_this, kart_item->m_info_proxy, true); };

                switch (mode)
                {
                case decltype(mode)::Default:
                    break;
                case decltype(mode)::Self:
                    use();
                    return true;
                case decltype(mode)::Both:
                    use();
                    break;
                }
            }
        }

        return false;
    }
}