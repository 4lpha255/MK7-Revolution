#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/game/item/kart_item.hpp>

#include <Item/ItemSlot.hpp>
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

    bool features::item::item_rapidfire::execute(s32 player_id)
    {
        if (auto const &kart_item = static_cast<game::item::kart_item *>(Item::KartItemProxy(player_id).m_kart_item); g_menu->m_item_rapidfire_entry->IsActivated() && kart_item->isMaster() && !kart_item->isNetRecv())
        {
            auto const &item_rapidfire = g_settings.m_options.item.item_rapidfire;
            auto const down = []()
            {
                switch (item_rapidfire.mode)
                {
                    case decltype(item_rapidfire.mode)::X: return CTRPluginFramework::Controller::IsKeyDown(CTRPluginFramework::Key::X);
                    case decltype(item_rapidfire.mode)::L: return CTRPluginFramework::Controller::IsKeyDown(CTRPluginFramework::Key::L);
                }

                return false;
            }
            ();

            auto &count = kart_item->m_item_rapidfire.count;
            auto &fire = kart_item->m_item_rapidfire.fire;

            if (down)
            {
                if (++count > item_rapidfire.delay)
                {
                    count = 0;
                    fire = true;
                }
                else
                {
                    fire = false;
                }
            }
            else
            {
                count = item_rapidfire.delay;
                fire = false;
            }

            return fire;
        }

        return false;
    }

    bool features::item::item_rapidfire::stock(Item::ItemSlot *_this)
    {
        return g_menu->m_item_rapidfire_entry->IsActivated() && _this->m_info_proxy->isMaster() && !_this->m_info_proxy->isNetRecv() && _this->m_state_observer.m_state_current == Item::ItemSlot::ObserverStatus_Stock;
    }
}