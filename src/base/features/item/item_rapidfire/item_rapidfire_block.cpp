#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <Item/ItemDirector.hpp>
#include <Item/KartItem.hpp>
#include <System/RootSystem.hpp>

namespace base
{
    sead::BitFlag32 features::item::item_rapidfire::block(sead::Controller *_this, s32 player_id)
    {
        auto &hold = _this->mPadHold;

        auto const &kart_item = g_pointers->m_root_system->get_item_director()->m_kart_items.at(player_id);

        if (g_menu->m_item_rapidfire_entry->IsActivated() && kart_item->isMaster() && !kart_item->isNetRecv())
        {
            auto const &item_rapidfire = g_settings.m_options.item.item_rapidfire;

            switch (item_rapidfire.mode)
            {
                case decltype(item_rapidfire.mode)::X: hold.resetBit(sead::Controller::cPadIdx_X); break;
                case decltype(item_rapidfire.mode)::L: hold.resetBit(sead::Controller::cPadIdx_L); break;
            }
        }

        return hold;
    }
}