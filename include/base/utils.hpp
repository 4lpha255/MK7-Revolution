#pragma once

#include <base/pointers.hpp>

#include <Item/ItemDirector.hpp>

#include <math/seadVector.h>

#include <magic_enum/magic_enum.hpp>

namespace base::utils
{
    inline u32 random_u32()
    {
        return (*g_pointers->m_global_random)->getU32();
    }

    inline u32 random_u32(u32 max)
    {
        return (*g_pointers->m_global_random)->getU32(max);
    }
    
    inline f32 random_f32()
    {
        return (*g_pointers->m_global_random)->getF32();
    }

    inline f32 random_f32(f32 min, f32 max)
    {
        return (*g_pointers->m_global_random)->getF32Range(min, max);
    }

    inline void emit_item(s32 player_id, Item::eItemType item, sead::Vector3f position, sead::Vector3f velocity)
    {
        if (auto const item_obj_director = Item::GetDirector()->getDirector_FromItemType(item); item_obj_director != nullptr)
            g_pointers->m_Item_ItemObjDirectorBase_emitItemImpl(item_obj_director, player_id, &position, &velocity);
    }

    template <typename type_t>
    typename std::enable_if_t<std::is_enum_v<type_t>>
    inline enum_next(type_t &out)
    {
        auto value = magic_enum::enum_underlying(out);
        auto count = magic_enum::enum_count<type_t>();

        value++;

        out = magic_enum::enum_value<type_t>(value % count);
    }
}