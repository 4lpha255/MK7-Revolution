#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/pointers.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <base/game/item/kart_item.hpp>
#include <base/game/kart/unit.hpp>

namespace base
{
	void features::item::item_wheel::calc(game::item::kart_item *_this)
	{
		using namespace CTRPluginFramework;

        if (g_menu->m_item_wheel_entry->IsActivated() && _this->isMaster() && !_this->isNetRecv())
        {
            auto const &item_wheel = g_settings.m_options.item.item_wheel;

            if (!item_wheel.items.empty())
            {
                if (item_wheel.cycler.enabled)
                {
                    if (++_this->m_item_wheel.count > item_wheel.cycler.delay)
                    {
                        _this->m_item_wheel.count = 0;
                        _this->m_item_wheel.index = utils::random_u32(item_wheel.items.size());
                    }
                }
                else
                {
                    // Don't switch items when changing Stalking target on the same frame
                    auto const &unit = static_cast<game::kart::unit *>(_this->m_info_proxy->m_vehicle->m_director->m_units.at(_this->m_player_id));

                    if (!unit->m_stalking.changed)
                    {
                        if (Controller::IsKeyPressed(Key::DPadLeft))
                            _this->m_item_wheel.index = (_this->m_item_wheel.index == SIZE_MAX ? item_wheel.items.size() - 1 : _this->m_item_wheel.index - 1);
                        if (Controller::IsKeyPressed(Key::DPadRight))
                            _this->m_item_wheel.index = (_this->m_item_wheel.index == item_wheel.items.size() - 1 ? SIZE_MAX : _this->m_item_wheel.index + 1);
                        if (Controller::IsKeyPressed(Key::DPadDown))
                            _this->m_item_wheel.index = SIZE_MAX;
                    }
                }

                if (_this->m_item_wheel.index < item_wheel.items.size())
                {
                    auto const item = *std::next(item_wheel.items.begin(), _this->m_item_wheel.index);

                    if (_this->m_stock_item != item || _this->m_stock_item_amount == 0)
                        g_pointers->m_Item_KartItem_setItemForce(_this, item);
                }
            }
        }
	}
}