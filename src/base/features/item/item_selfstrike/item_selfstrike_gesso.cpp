#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Item/ItemDirector.hpp>
#include <Item/ItemObj/ItemObjGesso.hpp>
#include <Item/KartItem.hpp>

namespace base
{
    void features::item::item_selfstrike::gesso(Item::ItemObjGesso *_this)
    {
        if (g_menu->m_item_selfstrike_entry->IsActivated())
        {
            // For some reason, owner player ID is -1 in Gesso (as well as player ID in Vehicle), so we have to resort to item ID
            auto const &kart_item = static_cast<Item::ItemDirector *>(static_cast<Item::ItemObjGessoDirector *>(_this->m_parent)->m_parent)->m_kart_items.at(_this->m_item_id);

            if (kart_item->isMaster() && !kart_item->isNetRecv())
            {
                auto const mode = g_settings.m_options.item.item_selfstrike.items.at(Item::eItemType::Gesso);

                switch (mode)
                {
                case decltype(mode)::Default:
                    break;
                case decltype(mode)::Self:
                    _this->m_other.fill(false);
                    _this->m_other[_this->m_item_id] = true;
                    break;
                case decltype(mode)::Both:
                    _this->m_other[_this->m_item_id] = true;
                    break;
                }
            }
        }
    }
}