#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_KartItem_calcBeforeStructure(game::item::kart_item *_this)
    {
        features::item::item_rain(_this);
        features::item::item_wheel_calc(_this);

        g_hooking->m_Item_KartItem_hook.get_original<decltype(&Item_KartItem_calcBeforeStructure)>(hooks::Director_calcBeforeStructure_index)(_this);
    }
}