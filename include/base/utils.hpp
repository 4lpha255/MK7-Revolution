#pragma once

#include <3ds/types.h>
#include <3ds/mii.h>

#include <base/pointers.hpp>

#include <Item/ItemDirector.hpp>
#include <RaceSys/ECourseID.hpp>
#include <RaceSys/ETitleType.hpp>

#include <math/seadVector.h>

#include <string>

namespace base
{
    namespace utils
    {
        u32 random_u32();
        u32 random_u32(u32 max);
        f32 random_f32();
        f32 random_f32(f32 min, f32 max);

        void emit_item(s32 player_id, Item::eItemType item, sead::Vector3f position, sead::Vector3f velocity);

        std::string item_name(Item::eItemSlot item);
        std::string item_name(Item::eItemType item);

        std::string course_name(RaceSys::ECourseID course);
        std::string title_name(RaceSys::ETitleType title);

        std::string mii_name(MiiData const &mii);
    }

    inline u32 utils::random_u32()
    {
        return (*g_pointers->m_global_random)->getU32();
    }

    inline u32 utils::random_u32(u32 max)
    {
        return (*g_pointers->m_global_random)->getU32(max);
    }
    
    inline f32 utils::random_f32()
    {
        return (*g_pointers->m_global_random)->getF32();
    }

    inline f32 utils::random_f32(f32 min, f32 max)
    {
        return (*g_pointers->m_global_random)->getF32Range(min, max);
    }

    inline void utils::emit_item(s32 player_id, Item::eItemType item, sead::Vector3f position, sead::Vector3f velocity)
    {
        if (auto const item_obj_director = Item::GetDirector()->getDirector_FromItemType(item); item_obj_director != nullptr)
            g_pointers->m_Item_ItemObjDirectorBase_emitItemImpl(item_obj_director, player_id, &position, &velocity);
    }
}