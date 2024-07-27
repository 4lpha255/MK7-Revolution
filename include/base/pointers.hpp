#pragma once

#include <forward.hpp>
#include <types.hpp>

#include "game_types.hpp"

#include <random/seadGlobalRandom.h>

namespace base
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();

		Net::NetworkEngine **m_network_engine;
		sead::GlobalRandom **m_global_random;
		System::RootSystem *m_root_system;

		void *m_Item_ItemDirector;
		void *m_Item_ItemObjGesso;
		void *m_Item_ItemObjKiller;
		void *m_Item_ItemObjKouraB;
		void *m_Item_ItemObjKouraG;
		void *m_Item_ItemObjKouraR;
		void *m_Item_ItemObjStar;
		void *m_Item_KartItem;
		void *m_Kart_Director;

		game_types::Item_ItemDirector_dropEquip_t m_Item_ItemDirector_dropEquip;
		game_types::Item_ItemObjBase_stateEquipHang_t m_Item_ItemObjBase_stateEquipHang;
		game_types::Item_ItemObjDirectorBase_emitItemImpl_t m_Item_ItemObjDirectorBase_emitItemImpl;
		game_types::Item_KartItem_setItemForce_t m_Item_KartItem_setItemForce;
		game_types::Kart_Unit_startJugemRecover_t m_Kart_Unit_startJugemRecover;
		game_types::Kart_VehicleMove_endKiller_t m_Kart_VehicleMove_endKiller;

		void *m_Effect_GPUPtclStripe_GPUPtclStripe_0x2D0;
		void *m_Effect_KartEffect_calcTireEffectWheelSpin;
		void *m_Item_GetExtraItemNum_0x8;
		void *m_Item_GetNumInItemType_0x8;
		void *m_Item_GetNumInItemTypeNet_0x8;
		void *m_Item_ItemDirector_entryItem;
		void *m_Item_ItemDirector_calcKeyInputEachPlayer_0x34;
		void *m_Item_ItemDirector_calcKeyInputEachPlayer_0x78;
		void *m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8;
		void *m_Item_ItemDirector_createBeforeStructure_0x548;
		void *m_Item_ItemDirector_itemEventRecvHandler;
		void *m_Item_ItemObjBase_setStateSelfMove;
		void *m_Item_ItemObjFlower_stateEquipHang;
		void *m_Item_ItemObjKouraB_stateEquipHang;
		void *m_Item_ItemObjKouraG_stateInitSelfMoveImpl;
		void *m_Item_ItemObjKouraR_stateInitComeBackDown;
		void *m_Item_ItemSlot_isStock;
		void *m_Item_KartItem_KartItem;
		void *m_Kart_NetData_read;
		void *m_Kart_NetData_send;
		void *m_Kart_Unit_calcMove;
		void *m_Kart_VehicleMove_calcMoveControlCommon_0x7EC;
		void *m_Kart_VehicleMove_startKillerImpl;
		void *m_Kart_VehicleReact_calcReact_0x20;
		void *m_Kart_VehicleReact_reactAccidentCommon;
		void *m_Menu3D_GarageDirector_isEndMiiIntroduction;
		void *m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived;
		void *m_Net_NetworkEngine_sendUnreliableCore;
		void *m_Net_NetworkEventModule_calc_0xB4;
		void *m_Net_NetworkFriendsManager_updateFriendInfo;
		void *m_Net_NetworkItemSlotMgr_Buffer_setEquipItemType;
		void *m_RaceSys_LapRankChecker_calcLapPosition;
		void *m_RaceSys_ModeManagerRace_calcCountDown_0x18;
		void *m_Sequence_BaseRacePage_subEquipItem_0xAC;
		void *m_sead_PtrArrayImpl_allocBuffer;
		void *m_System_KDPadInputer_calcInput;

		std::size_t *m_network_buffer_sizes;

		float *m_miniturbo_blue_threshold;
		float *m_miniturbo_red_threshold;
		s32 *m_invincibility_frames_invisible_amount;
		s32 *m_invincibility_frames_visible_amount;
		float *m_press_frames_kart_size;
	};

	inline pointers *g_pointers{};
}