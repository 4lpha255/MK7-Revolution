#pragma once

#include <forward.hpp>

#include <Item/eItemSlot.hpp>
#include <Kart/VehicleReact.hpp> // Kart::VehicleReact::EAcdType, Kart::VehicleReact::ECallType
#include <Net/NetworkItemEventDataMgr.hpp> // Net::NetworkItemEventDataMgr::SlotData
#include <Net/NetworkItemSlotMgr.hpp> // Net::NetworkItemSlotMgr::Buffer
#include <RaceSys/LapRankChecker.hpp> // RaceSys::LapRankChecker::KartInfo

#include <container/seadPtrArray.h>
#include <gfx/seadColor.h>
#include <math/seadVectorFwd.h>

#include <base/game/forward.hpp>

namespace base
{
    struct hooks
    {
        static constexpr size_t Director_count = 34;
        static constexpr size_t Director_createBeforeStructure_index = 18;
        static constexpr size_t Director_initBeforeStructure_index = 20;
        static constexpr size_t Director_calcBeforeStructure_index = 22;
        static constexpr size_t ItemObjBase_count = 68;
        static constexpr size_t ItemObjBase_initEntryInnerBefore = 31;
        static constexpr size_t ItemObjBase_stateInitSelfMoveImpl_index = 41;
        static constexpr size_t ItemObjBase_stateEquipHang_index = 55;
        static constexpr size_t ItemObjKoura_count = 87;
        static constexpr size_t ItemObjKoura_getStripeColor_index = 70;
        static constexpr size_t ItemObjKoura_stateInitComeBackDown_index = 80;
        
        // VMT hooks
        static void Item_ItemDirector_calcBeforeStructure(Item::ItemDirector *);
        static void Item_ItemObjGesso_initEntryInnerBefore(Item::ItemObjGesso *);
        static void Item_ItemObjKouraB_getStripeColor(sead::Color4f *);
        static void Item_ItemObjKouraG_getStripeColor(sead::Color4f *);
        static void Item_ItemObjKouraR_getStripeColor(sead::Color4f *);
        static void Item_ItemObjStar_initEntryInnerBefore(Item::ItemObjStar *);
        static void Item_KartItem_calcBeforeStructure(Item::KartItem *);
        static void Item_KartItem_initBeforeStructure(Item::KartItem *);
        static void Kart_Director_calcBeforeStructure(Kart::Director *);

        // Detour hooks
        static void Effect_KartEffect_calcTireEffectWheelSpin(Effect::KartEffect *);
        static void Item_ItemDirector_entryItem(Item::ItemDirector *, Item::eItemSlot, game::item::kart_item *);
        static bool Item_ItemDirector_itemEventRecvHandler(Item::ItemDirector *, Net::NetworkItemEventDataMgr::SlotData *);
        static void Item_ItemObjBase_setStateSelfMove(Item::ItemObjBase *, sead::Vector2f *);
        static void Item_ItemObjFlower_stateEquipHang(Item::ItemObjFlower *);
        static void Item_ItemObjKouraB_stateEquipHang(Item::ItemObjKouraB *);
        static void Item_ItemObjKouraG_stateInitSelfMoveImpl(Item::ItemObjKouraG *);
		static void Item_ItemObjKouraR_stateInitComeBackDown(Item::ItemObjKouraR *);
        static bool Item_ItemSlot_isStock(Item::ItemSlot *);
        static game::item::kart_item *Item_KartItem_KartItem(game::item::kart_item *, s32);
        static bool Kart_NetData_read(Kart::NetData *, Net::NetworkBuffer *, Kart::NetData **, Kart::NetData **);
        static void Kart_NetData_send(Kart::NetData *, s32);
        static void Kart_Unit_calcMove(Kart::Unit *, bool, bool);
        static void Kart_VehicleMove_startKillerImpl(Kart::VehicleMove *, bool);
        static bool Kart_VehicleReact_reactAccidentCommon(Kart::VehicleReact *, Kart::VehicleReact::ECallType, int, int, Kart::VehicleReact::EAcdType, sead::Vector3f *, sead::Vector3f *);
        static bool Menu3D_GarageDirector_isEndMiiIntroduction(Menu3D::GarageDirector *);
        static bool Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived(void *, Net::NetworkReceivedInfo *);
        static void Net_NetworkEngine_sendUnreliableCore(Net::NetworkEngine *, u32, Net::NetworkBuffer *);
        static void Net_NetworkFriendsManager_updateFriendInfo(Net::NetworkFriendsManager *);
        static void Net_NetworkItemSlotMgr_Buffer_setEquipItemType(Net::NetworkItemSlotMgr::Buffer *, s32, Item::eItemSlot, s32);
        static void RaceSys_LapRankChecker_calcLapPosition(RaceSys::LapRankChecker *, RaceSys::LapRankChecker::KartInfo *);
        static void sead_PtrArrayImpl_allocBuffer(sead::PtrArrayImpl *, s32, sead::Heap *, s32);
        static void System_KDPadInputer_calcState(System::KDPadInputer *);

        // Naked hooks
        static NAKED void Item_GetExtraItemNum_0x8();
        static NAKED void Item_GetNumInItemType_0x8();
        static NAKED void Item_GetNumInItemTypeNet_0x8();
        static NAKED void Item_ItemDirector_calcKeyInputEachPlayer_0x34();
        static NAKED void Item_ItemDirector_calcKeyInputEachPlayer_0x78();
        static NAKED void Item_ItemDirector_calcKeyInputEachPlayer_0xE8();
        static NAKED void Item_ItemDirector_createBeforeStructure_0x548();
        static NAKED void Kart_VehicleMove_calcMoveControlCommon_0x7EC();
        static NAKED void Kart_VehicleReact_calcReact_0x20();
        static NAKED void Net_NetworkEventModule_calc_0xB4();
        static NAKED void RaceSys_ModeManagerRace_calcCountDown_0x18();
        static NAKED void Sequence_BaseRacePage_subEquipItem_0xAC();
    };
}