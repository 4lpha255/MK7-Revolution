#pragma once

#include <forward.hpp>

#include <Item/eItemSlot.hpp>
#include <Kart/VehicleMove.hpp> // Kart::VehicleMove::StatusFlags
#include <Net/NetworkEventModule.hpp> // Net::NetworkEventModule::Slot
#include <Net/NetworkItemEventDataMgr.hpp> // Net::NetworkItemEventDataMgr::SlotData
#include <RaceSys/ERaceRuleMode.hpp>
#include <RaceSys/ModeManagerBase.hpp> // RaceSys::ModeManagerBase::ERaceState

#include <controller/seadController.h> // sead::Controller
#include <gfx/seadColor.h>
#include <prim/seadBitFlag.h> // sead::BitFlag32

#include <base/game/forward.hpp>

#include <optional>

namespace base
{
	struct features
	{
		struct item
		{
			struct disable_item_clear
			{
				static bool recover(Item::ItemDirector *, s32);
				static bool thunder(Item::ItemDirector *, s32);
			};

			struct item_hang
			{
				static bool base(Item::ItemObjBase *);
				static bool entry(Item::ItemDirector *, Item::eItemSlot, game::item::kart_item *);
				static Item::eItemType icon(Item::eItemType);
				static void init(Item::ItemObjBase *);
			};

			struct item_limiters
			{
				static std::optional<s32> extra_num(Item::eItemType);
				static std::optional<s32> num(Item::eItemType);
				static void stripes(s32 &);
			};

			struct item_rapidfire
			{
				static sead::BitFlag32 block(sead::Controller *, s32 player_id);
				static bool execute(s32);
				static bool stock(Item::ItemSlot *);
			};

			struct item_selfstrike
			{
				static void gesso(Item::ItemObjGesso *);
				static bool thunder(Item::ItemObjThunderDirector *, s32);
			};

			struct item_usage
			{
				static s32 dokan(Kart::Vehicle *);
				static bool goal(Kart::Vehicle *);
				static Kart::VehicleMove::StatusFlags statuses(Kart::Vehicle *);
			};

			struct item_wheel
			{
				static void calc(game::item::kart_item *);
				static RaceSys::ERaceRuleMode sound(RaceSys::CRaceInfo *, Item::KartItemProxy *);
			};

			static bool blue_shell_battle_crash_fix(Item::ItemObjKouraR *);
			static void item_drop(Item::ItemObjBase *);
			static void item_rain(game::item::kart_item *);
			static void item_terrain(game::item::kart_item *);
			static bool rainbow_shell_stripes(sead::Color4f *);
			static void zero_gravity_shells(Item::ItemObjKouraG *);
		};

		struct kart
		{
			static constexpr s32 c_status_threshold = 1 << 2;
			static constexpr s32 c_respawn_threshold = 1;

			struct future_fly
			{
				static void calc(game::kart::unit *);
				static bool velocity(Kart::Rigid *);
			};

			struct instant_miniturbo
			{
				static void calc(game::kart::unit *);
				static float effect(Kart::VehicleMove *);
			};

			struct killer_control
			{
				static void move(Kart::VehicleMove *, float);
				static void start(Kart::VehicleMove *, bool &);
				static bool toggle(Item::ItemObjKiller *);
			};

			static void instant_acceleration(game::kart::unit *);
			static void instant_respawn(game::kart::unit *);
			static bool intangibility(Kart::VehicleReact *);
			static bool invincibility(Kart::VehicleReact *);
			static void kart_statuses(game::kart::unit *);
			static Kart::VehicleMove::StatusFlags kart_usage(Kart::Vehicle *);
		};

		struct mode
		{
			struct drive_during_sync
			{
				static void after(RaceSys::ModeManagerBase *, RaceSys::ModeManagerBase::RaceState);
				static RaceSys::ModeManagerBase::RaceState before(RaceSys::ModeManagerBase *);
				static bool bottom_screen(bool);
				static bool input(System::KDPadInputer *);
			};

			static void stalking(game::kart::unit *);
			static void trigger_respawn(game::kart::unit *);
		};

		struct network
		{
			enum class mii_matching_viewer_result_t
			{
				run_original,
				wait_button,
				skip_mii,
			};

			struct item_delimiters
			{
				static void entry(Item::eItemSlot, game::item::kart_item *);
				static void equip(s32, Item::eItemSlot &, s32 &);
			};

			struct protections
			{
				static bool item(Item::ItemDirector *, Net::NetworkItemEventDataMgr::SlotData *);
				static bool kart(Kart::NetData *);
				static bool system_info(Net::NetworkReceivedInfo *);
			};

			static void disable_idle_disconnect(RaceSys::LapRankChecker *);
			static void disable_killer_lag(Kart::NetData *);
			static u32 event_frame_modifier(Net::NetworkEventModule::Slot *);
			static std::optional<s32> force_replacement(Item::eItemType);
			static void friend_info_modifier(Net::NetworkFriendsManager *);
			static void goal_score_modifier(u32 &);
			static void high_data_rate(u32 &);
			static void invisibility(Kart::NetData *);
			static void kart_warp(Kart::NetData *);
			static mii_matching_viewer_result_t mii_matching_viewer();
		};

		static size_t kart_director_size();
		static void kart_director_create(game::kart::director *);
		static size_t kart_unit_size();
		static void kart_unit_ctor(game::kart::unit *);
		static size_t kart_item_size();
		static void kart_item_ctor(game::item::kart_item *);
	};
}