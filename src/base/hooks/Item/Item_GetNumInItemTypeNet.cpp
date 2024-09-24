#include <base/hooking.hpp>
#include <base/features.hpp>

#include <Item/Num/GetNum_InItemType_Net.hpp>

namespace base
{
    void hooks::Item_GetNumInItemTypeNet()
    {
        asm volatile
        (
            "b __force_replacement\n"
        );
    }

    extern "C" auto __force_replacement(Item::eItemType item_type)
    {
        return features::network::force_replacement(item_type).value_or(Item::GetNum_InItemType_Net(item_type));
    }
}