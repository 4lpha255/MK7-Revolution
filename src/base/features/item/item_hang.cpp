#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <base/game/item/kart_item.hpp>

#include <Item/ItemDirector.hpp>
#include <Item/ItemObj/ItemObjBase.hpp>

namespace base
{
    bool features::item::item_hang::base(Item::ItemObjBase *_this)
    {
        auto enabled = g_menu->m_item_hang_entry->IsActivated() && g_settings.m_options.item.item_hang.items.contains(_this->m_item_type);

        if (enabled)
            g_pointers->m_Item_ItemObjBase_stateEquipHang(_this);

        return enabled;
    }

    bool features::item::item_hang::entry(Item::ItemDirector *_this, Item::eItemSlot item, game::item::kart_item *kart_item)
    {
        if (g_menu->m_item_hang_entry->IsActivated())
        {
            switch (item)
            {
            case decltype(item)::Kinoko:
            case decltype(item)::Gesso:
            case decltype(item)::Star:
                if (auto const item_type = Item::ItemDirector::getItemType_FromItemSlot(item); item_type != Item::eItemType::INVALID)
                    if (g_settings.m_options.item.item_hang.items.at(item_type))
                        if (_this->getDirector_FromItemType(item_type)->entry(kart_item->m_info_proxy, true, -1) != nullptr)
                        {
                            kart_item->setEquipInfo(item, Item::eEquipType::Hang, 1, true);
                            return true;
                        }
                break;
            default:
                break;
            }
        }

        return false;
    }

    Item::eItemType features::item::item_hang::icon(Item::eItemType item)
    {
        if (g_menu->m_item_hang_entry->IsActivated())
        {
            switch (item)
            {
            case Item::eItemType::KouraB:
            case Item::eItemType::Flower:
                if (g_settings.m_options.item.item_hang.items.contains(item))
                    item = Item::eItemType::KouraG;
                break;
            default:
                break;
            }
        }
        
        return item;
    }

    void features::item::item_hang::init(Item::ItemObjBase *_this)
    {
        if (g_menu->m_item_hang_entry->IsActivated() && g_settings.m_options.item.item_hang.items.at(_this->m_item_type))
        {
            _this->m_is_dropped = true;
        }
    }
}