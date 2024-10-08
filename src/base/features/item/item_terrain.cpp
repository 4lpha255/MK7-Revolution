#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <base/game/item/kart_item.hpp>

#include <Field/Accessor/all.hpp>

namespace base
{
    void features::item::item_terrain(game::item::kart_item *_this)
    {
        if (g_menu->m_item_terrain_entry->IsActivated() && _this->isMaster() && !_this->isNetRecv())
        {
            auto const &item_terrain = g_settings.m_options.item.item_terrain;

            if (!item_terrain.items.empty() && ++_this->m_item_terrain.count > item_terrain.delay)
            {
                _this->m_item_terrain.count = 0;

                auto const position_optional = []() -> std::optional<sead::Vector3f>
                {
                    switch (item_terrain.mode)
                    {
                    case decltype(item_terrain.mode)::EnemyPoint:
                        if (auto const accessor = Field::GetEnemyPointAccessor(); !accessor->m_entries.isEmpty())
                            return accessor->m_entries.at(utils::random_u32(accessor->m_entries.size()))->m_data->position;
                        break;
                    case decltype(item_terrain.mode)::ItemPoint:
                        if (auto const accessor = Field::GetItemPointAccessor(); !accessor->m_entries.isEmpty())
                            return accessor->m_entries.at(utils::random_u32(accessor->m_entries.size()))->m_data->position;
                        break;
                    case decltype(item_terrain.mode)::JugemPoint:
                        if (auto const accessor = Field::GetJugemPointAccessor(); !accessor->m_entries.isEmpty())
                            return accessor->m_entries.at(utils::random_u32(accessor->m_entries.size()))->m_data->position;
                        break;
                    case decltype(item_terrain.mode)::StartPoint:
                        if (auto const accessor = Field::GetStartPointAccessor(); !accessor->m_entries.isEmpty())
                            return accessor->m_entries.at(utils::random_u32(accessor->m_entries.size()))->m_data->position;
                        break;
                    }
                    return {};
                }();

                if (position_optional.has_value())
                {
                    auto const player_id = _this->m_info_proxy->m_vehicle->m_player_id;
                    auto const item = *std::next(item_terrain.items.begin(), utils::random_u32(item_terrain.items.size()));
                    auto const position = position_optional.value();
                    auto const velocity = -sead::Vector3f::ey;

                    utils::emit_item(player_id, item, position, velocity);
                }
            }
        }
    }
}