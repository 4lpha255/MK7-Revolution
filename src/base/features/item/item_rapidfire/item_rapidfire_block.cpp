#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Item/KartItem.hpp>
#include <Item/KartItemProxy.hpp>

namespace base
{
    sead::BitFlag32 features::item::item_rapidfire::block(sead::Controller *_this, s32 player_id)
    {
        auto &hold = _this->mPadHold;

        if (auto const &kart_item = Item::KartItemProxy(player_id).m_kart_item; g_menu->m_item_rapidfire_entry->IsActivated() && kart_item->isMaster() && !kart_item->isNetRecv())
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