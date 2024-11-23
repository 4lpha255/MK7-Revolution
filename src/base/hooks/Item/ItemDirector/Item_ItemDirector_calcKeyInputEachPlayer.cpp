#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    void hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x34()
    {
        asm volatile
        (
            "push {r0, lr}\n"
            "bl __item_usage_statuses\n"
            "mov r1, r0\n"
            "pop {r0, pc}\n"
        );
    }

    extern "C" auto __item_usage_statuses(Kart::Vehicle *_this)
    {
        return features::item::item_usage::statuses(_this);
    }

    void hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x58()
    {
        asm volatile
        (
            "push {r0, lr}\n"
            "bl __item_usage_dokan\n"
            "mov r1, r0\n"
            "pop {r0, pc}\n"
        );
    }

    extern "C" auto __item_usage_dokan(Kart::Vehicle *_this)
    {
        return features::item::item_usage::dokan(_this);
    }

    void hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x64()
    {
        asm volatile
        (
            "push {r0, lr}\n"
            "bl __item_usage_goal\n"
            "mov r1, r0\n"
            "pop {r0, pc}\n"
        );
    }

    extern "C" auto __item_usage_goal(Kart::Vehicle *_this)
    {
        return features::item::item_usage::goal(_this);
    }

    void hooks::Item_ItemDirector_calcKeyInputEachPlayer_0x78()
    {
        asm volatile
        (
            "push {lr}\n"
            "mov r1, r5\n"
            "bl __item_rapidfire_block\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __item_rapidfire_block(sead::Controller *_this, s32 player_id)
    {
        return features::item::item_rapidfire::block(_this, player_id);
    }

    void hooks::Item_ItemDirector_calcKeyInputEachPlayer_0xE8()
    {
        asm volatile
        (
            "push {lr}\n"
            "mov r0, r5\n"
            "bl __item_rapidfire_execute\n"
            "mov r8, r0\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __item_rapidfire_execute(s32 player_id)
    {
        return features::item::item_rapidfire::execute(player_id);
    }
}