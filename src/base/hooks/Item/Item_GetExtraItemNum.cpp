#include <base/hooking.hpp>
#include <base/features.hpp>

#include <Item/Num/GetExtraItemNum.hpp>

namespace base
{
    void hooks::Item_GetExtraItemNum()
    {
        asm volatile
        (
            "b __item_limiters_extra_num\n"
        );
    }

    extern "C" auto __item_limiters_extra_num(Item::eItemType item_type)
    {
        return features::item::item_limiters::extra_num(item_type).value_or(Item::GetExtraItemNum(item_type));
    }
}