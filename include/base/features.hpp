#pragma once

#include <forward.hpp>

#include <Item/eItemSlot.hpp>
#include <Kart/VehicleMove.hpp> // Kart::VehicleMove::StatusFlags
#include <Net/NetworkEventModule.hpp> // Net::NetworkEventModule::Slot
#include <Net/NetworkItemEventDataMgr.hpp> // Net::NetworkItemEventDataMgr::SlotData
#include <RaceSys/ModeManagerBase.hpp> // RaceSys::ModeManagerBase::ERaceState

#include <controller/seadController.h> // sead::Controller
#include <gfx/seadColor.h>
#include <prim/seadBitFlag.h> // sead::BitFlag32

#include <base/game/forward.hpp>

namespace base
{
	struct features
	{
		struct item
		{
			static bool blue_shell_battle_crash_fix(Item::ItemObjKouraR *);
			static void item_drop(Item::ItemObjBase *);
			static bool item_hang_base(Item::ItemObjBase *);
			static bool item_hang_entry(Item::ItemDirector *, Item::eItemSlot, game::item::kart_item *);
			static Item::eItemType item_hang_icon(Item::eItemType);
			static void item_hang_init(Item::ItemObjBase *);
			static s32 item_limiters_extra_num(Item::eItemType);
			static s32 item_limiters_num(Item::eItemType);
			static void item_limiters_stripes(s32 &);
			static void item_rain(game::item::kart_item *);
			static sead::BitFlag32 item_rapidfire_block(sead::Controller *);
			static bool item_rapidfire_execute(s32);
			static bool item_rapidfire_stock(Item::ItemSlot *);
			static s32 item_usage_dokan(Kart::Vehicle *);
			static bool item_usage_goal(Kart::Vehicle *);
			static Kart::VehicleMove::StatusFlags item_usage_statuses(Kart::Vehicle *);
			static void item_wheel_calc(game::item::kart_item *);
			static bool rainbow_shell_stripes(sead::Color4f *);
			static void zero_gravity_shells(Item::ItemObjKouraG *);
		};

		struct kart
		{
			static void killer_control_start(Kart::VehicleMove *, bool &);
			static void killer_control_move(Kart::VehicleMove *, float);
			static bool killer_control_toggle(Item::ItemObjKiller *);
			static void instant_miniturbo(Kart::Unit *);
			static void instant_respawn(Kart::Unit *);
			static bool intangibility(Kart::VehicleReact *);
			static bool invincibility(Kart::VehicleReact *);
			static void kart_statuses(Kart::Unit *);

			static constexpr s32 c_status_threshold = 1 << 2;
			static constexpr s32 c_respawn_threshold = 1;
		};

		struct mode
		{
			static void drive_during_sync_after(RaceSys::ModeManagerBase *, RaceSys::ModeManagerBase::ERaceState);
			static RaceSys::ModeManagerBase::ERaceState drive_during_sync_before(RaceSys::ModeManagerBase *);
			static bool drive_during_sync_bottom_screen(bool);
			static bool drive_during_sync_input(System::KDPadInputer *);
			static void trigger_respawn(Kart::Unit *);
		};

		struct network
		{
			enum class mii_matching_viewer_result_t
			{
				run_original,
				wait_button,
				skip_mii,
			};

			static u32 event_frame_modifier(Net::NetworkEventModule::Slot *);
			static s32 force_replacement(Item::eItemType);
			static void friend_info_modifier(Net::NetworkFriendsManager *);
			static void high_data_rate(u32 *);
			static void invisibility(Kart::NetData *);
			static void item_delimiters_entry(Item::eItemSlot, game::item::kart_item *);
			static void item_delimiters_equip(s32, Item::eItemSlot &, s32 &);
			static void kart_warp(Kart::NetData *);
			static mii_matching_viewer_result_t mii_matching_viewer();
			static void disable_idle_disconnect(RaceSys::LapRankChecker *);
			static bool protections_item(Item::ItemDirector *, Net::NetworkItemEventDataMgr::SlotData *);
			static bool protections_kart(Kart::NetData *);
			static bool protections_system_info(Net::NetworkReceivedInfo *);
		};

		static size_t kart_item_size();
		static void kart_item_ctor(game::item::kart_item *);
	};
}