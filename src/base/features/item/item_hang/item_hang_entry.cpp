#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Item/eItemSlot.hpp>
#include <Item/ItemDirector.hpp>
#include <Item/KartItem.hpp>

namespace base
{
    bool features::item::item_hang_entry(Item::ItemDirector *_this, Item::eItemSlot item, Item::KartItem *kart_item)
    {
        if (g_menu->m_item_hang_entry->IsActivated())
        {
            switch (item)
            {
            case decltype(item)::Kinoko:
            case decltype(item)::Star:
                if (auto const item_type = Item::ItemDirector::getItemType_FromItemSlot(item); item_type != Item::eItemType::INVALID)
                    if (g_settings.m_options.item.item_hang.items.at(item_type))
                        if (_this->getDirector_FromItemType(item_type)->entry(kart_item->m_info_proxy, true, -1) != nullptr)
                        {
                            kart_item->setEquipInfo(item, Item::eEquipType::Hang, 1, true);
                            return true;
                        }
                break;
            }
        }

        return false;
    }
}