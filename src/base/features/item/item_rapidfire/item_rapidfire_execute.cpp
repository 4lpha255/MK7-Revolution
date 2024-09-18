#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>

#include <base/game/item/kart_item.hpp>

#include <Item/ItemDirector.hpp>
#include <System/RootSystem.hpp>

namespace base
{
    bool features::item::item_rapidfire::execute(s32 player_id)
    {
        auto result = false;

        if (g_menu->m_item_rapidfire_entry->IsActivated())
        {
            auto const &item_rapidfire = g_settings.m_options.item.item_rapidfire;
            
            auto is_down = false;

            switch (item_rapidfire.mode)
            {
                case decltype(item_rapidfire.mode)::X: is_down = CTRPluginFramework::Controller::IsKeyDown(CTRPluginFramework::Key::X); break;
                case decltype(item_rapidfire.mode)::L: is_down = CTRPluginFramework::Controller::IsKeyDown(CTRPluginFramework::Key::L); break;
            }

            auto &count = static_cast<game::item::kart_item *>(g_pointers->m_root_system->get_item_director()->m_kart_items.at(player_id))->m_item_rapidfire.count;

            if (is_down)
            {
                if (++count > item_rapidfire.delay)
                {
                    count = 0;
                    result = true;
                }
            }
            else
                count = item_rapidfire.delay;
        }

        return result;
    }
}