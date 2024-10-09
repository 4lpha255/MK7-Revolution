#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/game/item/kart_item.hpp>

#include <Item/KartItemProxy.hpp>

namespace base
{
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
}