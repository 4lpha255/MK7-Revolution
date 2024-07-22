#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Item/eItemType.hpp>

namespace base
{
    Item::eItemType features::item::item_hang_icon(Item::eItemType item)
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
            }
        }
        
        return item;
    }
}