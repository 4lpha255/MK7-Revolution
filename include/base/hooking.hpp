#pragma once

#include "hook_types/detour_hook.hpp"
#include "hook_types/naked_hook.hpp"
#include "hook_types/vmt_hook.hpp"

#include "hooks.hpp"

namespace base
{
    class hooking
    {
        friend hooks;

	public:
		explicit hooking();
		~hooking();

        inline bool is_enabled() const { return m_enabled; }

        void enable();
		void disable();

    private:
        bool m_enabled{};

        hook_types::vmt_hook m_Item_ItemDirector_hook;
        hook_types::vmt_hook m_Item_ItemObjKouraB_hook;
        hook_types::vmt_hook m_Item_ItemObjKouraG_hook;
        hook_types::vmt_hook m_Item_ItemObjKouraR_hook;
        hook_types::vmt_hook m_Item_KartItem_hook;
        hook_types::vmt_hook m_Kart_Director_hook;

        hook_types::detour_hook m_Item_ItemDirector_itemEventRecvHandler_hook;
        hook_types::detour_hook m_Item_ItemObjBase_setStateSelfMove_hook;
        hook_types::detour_hook m_Item_ItemObjFlower_stateEquipHang_hook;
        hook_types::detour_hook m_Item_ItemObjKouraB_stateEquipHang_hook;
        hook_types::detour_hook m_Item_ItemObjKouraG_stateInitSelfMoveImpl_hook;
        hook_types::detour_hook m_Item_ItemObjKouraR_stateInitComeBackDown_hook;
        hook_types::detour_hook m_Item_ItemSlot_isStock_hook;
        hook_types::detour_hook m_Effect_KartEffect_calcTireEffectWheelSpin_hook;
        hook_types::detour_hook m_Kart_NetData_send_hook;
        hook_types::detour_hook m_Kart_Unit_calcMove_hook;
        hook_types::detour_hook m_Kart_VehicleReact_reactAccidentCommon_hook;
        hook_types::detour_hook m_Menu3D_GarageDirector_isEndMiiIntroduction_hook;
        hook_types::detour_hook m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived_hook;
        hook_types::detour_hook m_Net_NetworkEngine_sendUnreliableCore_hook;
        hook_types::detour_hook m_Net_NetworkFriendsManager_updateFriendInfo_hook;
        hook_types::detour_hook m_RaceSys_LapRankChecker_calcLapPosition_hook;
        hook_types::detour_hook m_sead_PtrArrayImpl_allocBuffer_hook;
        hook_types::detour_hook m_System_KDPadInputer_calcInput_hook;

        hook_types::naked_hook m_Item_GetExtraItemNum_0x8_hook;
        hook_types::naked_hook m_Item_GetNumInItemType_0x8_hook;
        hook_types::naked_hook m_Item_GetNumInItemTypeNet_0x8_hook;
        hook_types::naked_hook m_Item_ItemDirector_calcKeyInputEachPlayer_0x78_hook;
        hook_types::naked_hook m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8_hook;
        hook_types::naked_hook m_Kart_VehicleReact_calcReact_0x20_hook; // FIXME: CTRPF MITM Hook doesn't work on routines
        hook_types::naked_hook m_Net_NetworkEventModule_calc_0xB4_hook;
        hook_types::naked_hook m_RaceSys_ModeManagerRace_calcCountDown_0x18_hook;
    };

    inline hooking *g_hooking{};
}