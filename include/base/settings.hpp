#pragma once

#include <map>
#include <set>

#include <Item/eItemSlot.hpp>
#include <Item/eItemType.hpp>

namespace base
{
	class settings
	{
	public:
		explicit settings() = default;
		~settings() = default;

		bool load();
		bool store();
		bool reset();

		struct options
		{
			struct item
			{
				struct item_drop
				{
					enum class mode : u8 { Drop, Pop, } mode{ mode::Pop };
				}
				item_drop;

				struct item_hang
				{
					std::map<Item::eItemType, bool> items
					{
						{ Item::eItemType::Kinoko, true },
						{ Item::eItemType::Star, false },
						{ Item::eItemType::KouraB, true },
						{ Item::eItemType::Gesso, false },
						{ Item::eItemType::Flower, true },
					};
				}
				item_hang;

				struct item_limiters
				{
					struct items_value { bool enabled{ false }; u32 amount{ 0 }; };
					std::map<Item::eItemType, items_value> items
					{
						{ Item::eItemType::KouraB, { true, 8 } },
						{ Item::eItemType::Bomhei, { true, 32 } },
					};
				}
				item_limiters;

				struct item_rain
				{
					std::set<Item::eItemType> items
					{
						Item::eItemType::KouraG,
						Item::eItemType::KouraR,
						Item::eItemType::Banana,
						Item::eItemType::Kinoko,
						Item::eItemType::Star,
					};
					bool owned{ true };
					bool multi{ false };
					struct speed { bool enabled; float value; } speed{ true, 64.f };
					u32 delay{ 15 };
					enum class shape : u8 { Square, Circle, } shape{ shape::Square };
					float height{ 128.f };
					float width{ 256.f };
				}
				item_rain;

				struct item_rapidfire
				{
					enum class mode : u8 { X, L, } mode{ mode::L };
					u32 delay{ 5 };
				}
				item_rapidfire;

				struct item_usage
				{
					enum class type : u8 { Accident, Killer, Recover, };
					std::map<type, bool> toggles
					{
						{ type::Accident, false },
						{ type::Killer, true },
						{ type::Recover, false }
					};
				}
				item_usage;

				struct item_wheel
				{
					std::set<Item::eItemSlot> items
					{
						Item::eItemSlot::Banana,
						Item::eItemSlot::KouraG,
						Item::eItemSlot::KouraR,
						Item::eItemSlot::Kinoko,
						Item::eItemSlot::Bomhei,
						Item::eItemSlot::Gesso,
						Item::eItemSlot::KouraB,
						Item::eItemSlot::Star,
						Item::eItemSlot::Killer,
						Item::eItemSlot::Thunder,
						Item::eItemSlot::Flower,
						Item::eItemSlot::Tail,
						Item::eItemSlot::Seven,
					};
				}
				item_wheel;

				struct zero_gravity_shells
				{
					struct offset
					{
						bool enabled{ true };
						float value{ 2.f };
					}
					offset;
				}
				zero_gravity_shells;
			}
			item;

			struct kart
			{
				struct instant_miniturbo
				{
					enum class type : u8 { Blue, Red, } type{ type::Red };
				}
				instant_miniturbo;

				struct intangibility
				{
					bool invert{ true };
				}
				intangibility;

				struct kart_statuses
				{
					enum class status : u8 { Trick, Blink, Ink, Stun, Press, Star, Thunder, Draft, };
					std::map<status, bool> toggles
					{
						{ status::Trick, false },
						{ status::Blink, true },
						{ status::Ink, true },
						{ status::Stun, false },
						{ status::Press, false },
						{ status::Star, false },
						{ status::Thunder, false },
						{ status::Draft, false },
					};
				}
				kart_statuses;

				struct killer_control
				{
					bool toggle{ true };
				}
				killer_control;
			}
			kart;

			struct network
			{
				struct event_frame_modifier
				{
					u32 value{ 2 };
				}
				event_frame_modifier;

				struct force_replacement
				{
					std::set<Item::eItemType> items
					{
						{ Item::eItemType::KouraB },
						{ Item::eItemType::Thunder },
						{ Item::eItemType::Gesso },
					};
				}
				force_replacement;

				struct friend_info_modifier
				{
					struct principal_id
					{
						bool enabled{ false };
						bool notify{ true };
						enum class mode : u8 { Value, Random, } mode{ mode::Value };
						u32 value{ 1 };
					}
					principal_id;
				}
				friend_info_modifier;

				struct invisibility
				{
					enum class mode : u8 { Position, Velocity, } mode{ mode::Position };
				}
				invisibility;

				struct item_delimiters
				{
					std::map<Item::eItemSlot, bool> items
					{
						{ Item::eItemSlot::Gesso, true },
						{ Item::eItemSlot::Thunder, true },
					};
				}
				item_delimiters;

				struct protections
				{
					struct item
					{
						bool killer_items{ false };
						bool tail_items{ false };
					}
					item;

					struct kart
					{
						bool accident_type{ true };
					}
					kart;

					struct network
					{
						bool system_info{ true };
					}
					network;
				}
				protections;
			}
			network;
			
			struct base
			{
				struct rainbow
				{
					float hue_amount{ 1.f / 600.f };
					float saturation{ 1.f };
					float value{ 1.f };
				}
				rainbow;
			}
			base;
		}
		m_options{};

	private:
		bool load_impl();
	};

	inline settings g_settings;
}
