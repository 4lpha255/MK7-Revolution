#include <base/hooking.hpp>
#include <base/features.hpp>

#include <Item/Num/GetNum_InItemType.hpp>

namespace base
{
    void hooks::Item_GetNumInItemType()
    {
        asm volatile
        (
            "b __item_limiters_num\n"
        );
    }

    extern "C" auto __item_limiters_num(Item::eItemType item_type)
    {
        return features::item::item_limiters::num(item_type).value_or(Item::GetNum_InItemType(item_type));
    }
}