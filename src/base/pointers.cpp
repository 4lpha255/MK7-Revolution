#include <base/pointers.hpp>

#include <base/hooks.hpp>

#include <base/memory/all.hpp>

#include <System/RootSystem.hpp>

namespace base
{
	pointers::pointers()
	{
		auto batch = memory::batch();

		batch.add("Net::NetworkEngine", "B4 29 00 00 D4 27 00 00 78 78 00 00 F8 05 00 00", [this](memory::handle handle)
		{
			m_network_engine = *handle.add(0x1C).as<decltype(m_network_engine) *>();
		});

		batch.add("sead::Random", "00 00 54 E3 04 00 85 E5 04 00 A0 11 00 40 A0 03", [this](memory::handle handle)
		{
			m_global_random = *handle.add(0x20).as<decltype(m_global_random) *>();
		});

		batch.add("System::RootSystem", "00 20 95 E5 70 40 BD E8", [this](memory::handle handle)
		{
			m_root_system = System::g_root_system = *handle.add(0x20).as<decltype(m_root_system) *>();
		});

		batch.add("Item::ItemObjFlower", "00 30 92 E5 F8 31 80 E5 04 30 92 E5 FC 31 80 E5", [this](memory::handle handle)
		{
			auto Item_ItemObjFlower_vtbl = *handle.add(0x30).as<void ***>();
			auto Item_ItemObjFlower_stateEquipHang_hnd = memory::handle(Item_ItemObjFlower_vtbl[hooks::ItemObjBase_stateEquipHang_index]);

			m_Item_ItemObjFlower_stateEquipHang = Item_ItemObjFlower_stateEquipHang_hnd.as<decltype(m_Item_ItemObjFlower_stateEquipHang)>();
		});

		batch.add("Item::ItemObjGesso", "34 62 84 E5 05 0A 9F ED 38 62 84 E5 45 62 C4 E5", [this](memory::handle handle)
		{
			m_Item_ItemObjGesso = handle.add(0x1C).as<decltype(m_Item_ItemObjGesso)>();
		});

		batch.add("Item::ItemObjKiller", "00 10 A0 E3 49 11 C0 E5 4A 11 C0 E5 10 80 BD E8", [this](memory::handle handle)
		{
			m_Item_ItemObjKiller = handle.add(0x10).as<decltype(m_Item_ItemObjKiller)>();

			auto Item_ItemObjKiller_vtbl = *memory::handle(m_Item_ItemObjKiller).as<void ***>();
			auto Item_ItemObjKiller_stateInitUse_hnd = memory::handle(Item_ItemObjKiller_vtbl[hooks::ItemObjBase_stateInitUse_index]);
			
			m_Kart_VehicleMove_startKillerImpl = Item_ItemObjKiller_stateInitUse_hnd.add(0x58).jmp().add(0x8).as<decltype(m_Kart_VehicleMove_startKillerImpl)>();
		});

		batch.add("Item::ItemObjKouraB", "C4 12 80 E4 00 10 A0 E3 00 30 80 E5 01 20 A0 E3", [this](memory::handle handle)
		{
			m_Item_ItemObjKouraB = handle.add(0x30).as<decltype(m_Item_ItemObjKouraB)>();

			auto Item_ItemObjKouraB_vtbl = *memory::handle(m_Item_ItemObjKouraB).as<void ***>();
			auto Item_ItemObjKouraB_stateEquipHang_hnd = memory::handle(Item_ItemObjKouraB_vtbl[hooks::ItemObjBase_stateEquipHang_index]);

			m_Item_ItemObjBase_stateEquipHang = Item_ItemObjKouraB_stateEquipHang_hnd.add(0x8).jmp().as<decltype(m_Item_ItemObjBase_stateEquipHang)>();
			m_Item_ItemObjBase_setStateSelfMove = Item_ItemObjKouraB_stateEquipHang_hnd.add(0x18).jmp().as<decltype(m_Item_ItemObjBase_setStateSelfMove)>();
			m_Item_ItemObjKouraB_stateEquipHang = Item_ItemObjKouraB_stateEquipHang_hnd.as<decltype(m_Item_ItemObjKouraB_stateEquipHang)>();
		});

		batch.add("Item::ItemObjKouraG", "00 10 A0 E3 10 40 2D E9 ? ? ? EB 1C 10 9F E5", [this](memory::handle handle)
		{
			m_Item_ItemObjKouraG = handle.add(0x30).as<decltype(m_Item_ItemObjKouraG)>();

			auto Item_ItemObjKouraG_vtbl = *memory::handle(m_Item_ItemObjKouraG).as<void ***>();

			m_Item_ItemObjKouraG_stateInitSelfMoveImpl = Item_ItemObjKouraG_vtbl[hooks::ItemObjBase_stateInitSelfMoveImpl_index];
		});

		batch.add("Item::ItemObjKouraR", "01 10 A0 E3 10 40 2D E9 ? ? ? EB 3C 10 9F E5", [this](memory::handle handle)
		{
			m_Item_ItemObjKouraR = handle.add(0x50).as<decltype(m_Item_ItemObjKouraR)>();

			auto Item_ItemObjKouraR_vtbl = *memory::handle(m_Item_ItemObjKouraR).as<void ***>();

			m_Item_ItemObjKouraR_stateInitComeBackDown = Item_ItemObjKouraR_vtbl[hooks::ItemObjKoura_stateInitComeBackDown_index];
		});

		batch.add("Item::ItemObjStar", "01 20 A0 E1 04 10 A0 E3 10 40 2D E9 ? ? ? EB", [this](memory::handle handle)
		{
			m_Item_ItemObjStar = handle.add(0x1C).as<decltype(m_Item_ItemObjStar)>();
		});

		batch.add("Item::ItemObjThunder", "F8 11 80 E5 FC 11 C0 E5 FD 11 C0 E5 10 80 BD E8", [this](memory::handle handle)
		{
			auto Item_ItemObjThunder_vtbl = *handle.add(0x10).as<void ***>();
			auto Item_ItemObjThunder_stateInitAttacked_hnd = memory::handle(Item_ItemObjThunder_vtbl[hooks::ItemObjBase_stateInitAttacked_index]);

			m_Item_ItemDirector_clearItem = Item_ItemObjThunder_stateInitAttacked_hnd.add(0x178).jmp().as<decltype(m_Item_ItemDirector_clearItem)>();
			m_Item_ItemObjThunder_stateInitAttacked_0x17C = Item_ItemObjThunder_stateInitAttacked_hnd.add(0x17C).as<decltype(m_Item_ItemObjThunder_stateInitAttacked_0x17C)>();
		});

		batch.add("Item::ItemObjBananaDirector", "21 01 84 E8 48 D0 8D E2 F0 87 BD E8 01 00 A0 E3", [this](memory::handle handle)
		{
			auto Item_ItemObjBananaDirector_vtbl = *handle.add(0x3C).as<void ***>();
			auto Item_ItemObjBananaDirector_createBeforeStructure_hnd = memory::handle(Item_ItemObjBananaDirector_vtbl[hooks::Director_createBeforeStructure_index]);

			m_Item_GetExtraItemNum = Item_ItemObjBananaDirector_createBeforeStructure_hnd.add(0x18).jmp().as<decltype(m_Item_GetExtraItemNum)>();
			m_Item_GetNumInItemType = Item_ItemObjBananaDirector_createBeforeStructure_hnd.add(0xC).jmp().as<decltype(m_Item_GetNumInItemType)>();
		});

		batch.add("Object::CharacterEngine", "34 10 9F E5 3C 10 84 E5 00 60 C0 E5 04 00 A0 E1", [this](memory::handle handle)
		{
			auto Object_CharacterEngine_creators = handle.add(0x20).as<void **>();

			// For some reason, these routines are identical
			auto Object_CharacterEngine_creator_2 = memory::handle(Object_CharacterEngine_creators[2]);
			auto Object_CharacterEngine_creator_6 = memory::handle(Object_CharacterEngine_creators[6]);

			m_Object_CharacterEngine_creator_2_0x184 = Object_CharacterEngine_creator_2.add(0x184).as<decltype(m_Object_CharacterEngine_creator_2_0x184)>();
			m_Object_CharacterEngine_creator_6_0x184 = Object_CharacterEngine_creator_6.add(0x184).as<decltype(m_Object_CharacterEngine_creator_6_0x184)>();

			m_operator_new = Object_CharacterEngine_creator_2.add(0x18C).jmp().as<decltype(m_operator_new)>();

			// Kart::Director
			m_Kart_Director = Object_CharacterEngine_creator_2.add(0x198).jmp().add(0xDC).as<decltype(m_Kart_Director)>();

			auto Kart_Director_vtbl = *memory::handle(m_Kart_Director).as<void ***>();
			auto Kart_Director_createBeforeStructure_hnd = memory::handle(Kart_Director_vtbl[hooks::Director_createBeforeStructure_index]);
			auto Kart_Director_calcBeforeStructure_hnd = memory::handle(Kart_Director_vtbl[hooks::Director_calcBeforeStructure_index]);
			auto Kart_Unit_calcMove_hnd = Kart_Director_calcBeforeStructure_hnd.add(0x224).jmp();
			auto Kart_Unit_startJugemRecover_hnd = Kart_Unit_calcMove_hnd.add(0x1D8).jmp();

			m_Kart_Director_createBeforeStructure_0x284 = Kart_Director_createBeforeStructure_hnd.add(0x284).as<decltype(m_Kart_Director_createBeforeStructure_0x284)>();
			m_Kart_Unit_calcMove = Kart_Unit_calcMove_hnd.as<decltype(m_Kart_Unit_calcMove)>();
			m_Kart_Unit_startJugemRecover = Kart_Unit_startJugemRecover_hnd.as<decltype(m_Kart_Unit_startJugemRecover)>();
			m_Kart_Unit_startJugemRecover_0x60 = Kart_Unit_startJugemRecover_hnd.add(0x60).as<decltype(m_Kart_Unit_startJugemRecover_0x60)>();
			m_Kart_Unit_Unit = Kart_Director_createBeforeStructure_hnd.add(0x2A4).jmp().as<decltype(m_Kart_Unit_Unit)>();
			m_Kart_VehicleReact_calcReact_0x20 = Kart_Director_calcBeforeStructure_hnd.add(0x1E8).jmp().add(0x18).jmp().add(0x20).as<decltype(m_Kart_VehicleReact_calcReact_0x20)>();

			// Item::ItemDirector
			m_Item_ItemDirector = Object_CharacterEngine_creator_2.add(0x228).jmp().add(0xE8).as<decltype(m_Item_ItemDirector)>();
			m_Item_ItemDirector_itemEventRecvHandler = **handle.add(0x14).as<decltype(m_Item_ItemDirector_itemEventRecvHandler) **>();

			auto Item_ItemDirector_vtbl = *memory::handle(m_Item_ItemDirector).as<void ***>();
			auto Item_ItemDirector_createBeforeStructure_hnd = memory::handle(Item_ItemDirector_vtbl[hooks::Director_createBeforeStructure_index]);
			auto Item_ItemDirector_calcBeforeStructure_hnd = memory::handle(Item_ItemDirector_vtbl[hooks::Director_calcBeforeStructure_index]);
			auto Item_ItemDirector_calcKeyInputEachPlayer_hnd = Item_ItemDirector_calcBeforeStructure_hnd.add(0xDC).jmp();

			m_Item_ItemDirector_createBeforeStructure_0x548 = Item_ItemDirector_createBeforeStructure_hnd.add(0x548).as<decltype(m_Item_ItemDirector_createBeforeStructure_0x548)>();
			m_Item_ItemDirector_entryItem = Item_ItemDirector_calcKeyInputEachPlayer_hnd.add(0x218).jmp().as<decltype(m_Item_ItemDirector_entryItem)>();
			m_Item_ItemDirector_calcKeyInputEachPlayer_0x34 = Item_ItemDirector_calcKeyInputEachPlayer_hnd.add(0x34).as<decltype(m_Item_ItemDirector_calcKeyInputEachPlayer_0x34)>();
			m_Item_ItemDirector_calcKeyInputEachPlayer_0x58 = Item_ItemDirector_calcKeyInputEachPlayer_hnd.add(0x58).as<decltype(m_Item_ItemDirector_calcKeyInputEachPlayer_0x58)>();
			m_Item_ItemDirector_calcKeyInputEachPlayer_0x64 = Item_ItemDirector_calcKeyInputEachPlayer_hnd.add(0x64).as<decltype(m_Item_ItemDirector_calcKeyInputEachPlayer_0x64)>();
			m_Item_ItemDirector_calcKeyInputEachPlayer_0x78 = Item_ItemDirector_calcKeyInputEachPlayer_hnd.add(0x78).as<decltype(m_Item_ItemDirector_calcKeyInputEachPlayer_0x78)>();
			m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8 = Item_ItemDirector_calcKeyInputEachPlayer_hnd.add(0xE8).as<decltype(m_Item_ItemDirector_calcKeyInputEachPlayer_0xE8)>();
			m_Item_ItemSlot_isStock = Item_ItemDirector_calcKeyInputEachPlayer_hnd.add(0x1D0).jmp().as<decltype(m_Item_ItemSlot_isStock)>();
		});

		batch.add("Item::ItemDirector::drop_Equip", "70 40 2D E9 00 40 A0 E1 DC 00 9F E5 01 50 A0 E1", [this](memory::handle handle)
		{
			m_Item_ItemDirector_dropEquip = handle.as<decltype(m_Item_ItemDirector_dropEquip)>();
		});

		batch.add("Item::ItemObjDirectorBase::_emitItemImpl", "F0 43 2D E9 1C D0 4D E2 01 40 A0 E1 02 60 A0 E1", [this](memory::handle handle)
		{
			m_Item_ItemObjDirectorBase_emitItemImpl = handle.as<decltype(m_Item_ItemObjDirectorBase_emitItemImpl)>();
		});

		batch.add("Item::KartItem::KartItem", "B0 40 2D E9 00 70 A0 E3 00 70 80 E5 04 70 80 E5", [this](memory::handle handle)
		{
			m_Item_KartItem_KartItem = handle.as<decltype(m_Item_KartItem_KartItem)>();
			m_Item_KartItem = handle.add(0x17C).as<decltype(m_Item_KartItem)>();
		});

		batch.add("Item::KartItem::setItemForce", "70 40 2D E9 00 40 A0 E1 34 00 90 E5 01 50 A0 E1", [this](memory::handle handle)
		{
			m_Item_KartItem_setItemForce = handle.as<decltype(m_Item_KartItem_setItemForce)>();
		});

		batch.add("Kart::VehicleMove::endKiller", "04 00 A0 E1 10 40 BD E8 00 10 A0 E3 ? ? ? EA", [this](memory::handle handle)
		{
			m_Kart_VehicleMove_endKiller = handle.sub(0x20).as<decltype(m_Kart_VehicleMove_endKiller)>();
		});

		batch.add("Effect::GPUPtclStripe::GPUPtclStripe", "F0 4F 2D E9 BC D0 4D E2 02 40 A0 E3 00 50 A0 E3", [this](memory::handle handle)
		{
			auto Effect_GPUPtclStripe_GPUPtclStripe_0x2CC_hnd = handle.add(0x2CC);

			m_Effect_GPUPtclStripe_GPUPtclStripe_0x2D0 = Effect_GPUPtclStripe_GPUPtclStripe_0x2CC_hnd.add(0x4).as<decltype(m_Effect_GPUPtclStripe_GPUPtclStripe_0x2D0)>(); // Retrieve the return address of the allocBuffer call
			m_sead_PtrArrayImpl_allocBuffer = Effect_GPUPtclStripe_GPUPtclStripe_0x2CC_hnd.jmp().as<decltype(m_sead_PtrArrayImpl_allocBuffer)>();
		});

		batch.add("Effect::KartEffect::_calcTireEffect_WheelSpin", "70 40 2D E9 00 40 A0 E1 02 8B 2D ED 60 D0 4D E2", [this](memory::handle handle)
		{
			m_Effect_KartEffect_calcTireEffectWheelSpin = handle.as<decltype(m_Effect_KartEffect_calcTireEffectWheelSpin)>();
		});

		batch.add("Item::GetNum_InItemType_Net", "74 11 9F E5 00 30 A0 E1 00 00 E0 E3 04 10 91 E5", [this](memory::handle handle)
		{
			m_Item_GetNumInItemTypeNet = handle.as<decltype(m_Item_GetNumInItemTypeNet)>();
		});

		batch.add("Kart::NetData::read", "70 40 2D E9 00 00 51 E3 02 50 A0 E1 0C 20 91 15", [this](memory::handle handle)
		{
			m_Kart_NetData_read = handle.as<decltype(m_Kart_NetData_read)>();
		});

		batch.add("Kart::NetData::send", "30 40 2D E9 24 D0 4D E2 00 40 A0 E1 01 50 A0 E1 10 00 8D E2", [this](memory::handle handle)
		{
			m_Kart_NetData_send = handle.as<decltype(m_Kart_NetData_send)>();
		});

		batch.add("Kart::Rigid::updateVel", "30 40 2D E9 00 40 A0 E1 44 00 90 E5 0C D0 4D E2", [this](memory::handle handle)
		{
			m_Kart_Rigid_updateVel = handle.as<decltype(m_Kart_Rigid_updateVel)>();
		});

		batch.add("Kart::VehicleMove::calcMoveControlCommon", "F0 4F 2D E9 01 6A 80 E2 00 40 A0 E1 04 8B 2D ED", [this](memory::handle handle)
		{
			m_Kart_VehicleMove_calcMoveControlCommon_0x7EC = handle.add(0x7EC).as<decltype(m_Kart_VehicleMove_calcMoveControlCommon_0x7EC)>();
		});

		batch.add("Kart::VehicleMove::calcMoveControlGnd", "F0 4F 2D E9 00 50 A0 E1 03 1B 85 E2 F9 1F 81 E2", [this](memory::handle handle)
		{
			m_Kart_VehicleMove_calcMoveControlGnd_0x18 = handle.add(0x18).as<decltype(m_Kart_VehicleMove_calcMoveControlGnd_0x18)>();
		});

		batch.add("Kart::VehicleMove::isMiniTurbo_OverLv1+0x8", "1C 10 9F E5 03 0B 80 E2 C2 0A 90 ED 4B 0A D1 ED", [this](memory::handle handle)
		{
			m_Kart_VehicleMove_isMiniTurboOverLv1_0x8 = handle.add(0x8).as<decltype(m_Kart_VehicleMove_isMiniTurboOverLv1_0x8)>();
		});

		batch.add("Kart::VehicleReact::reactAccidentCommon", "FF 4F 2D E9 0C D0 4D E2 00 40 A0 E1 01 5A 84 E2", [this](memory::handle handle)
		{
			m_Kart_VehicleReact_reactAccidentCommon = handle.as<decltype(m_Kart_VehicleReact_reactAccidentCommon)>();
		});

		batch.add("Menu3D::GarageDirector::isEndMiiIntroduction", "3C 00 90 E5 E6 00 D0 E5 00 00 50 E3 01 00 A0 03", [this](memory::handle handle)
		{
			m_Menu3D_GarageDirector_isEndMiiIntroduction = handle.as<decltype(m_Menu3D_GarageDirector_isEndMiiIntroduction)>();
		});

		batch.add("Net::NetworkDataManager<Net::NetworkSystemSendFormat>::onReceived", "70 40 2D E9 00 40 A0 E1 EC 00 D0 E5 01 60 A0 E1", [this](memory::handle handle)
		{
			m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived = handle.as<decltype(m_Net_NetworkDataManager_Net_NetworkSystemSendFormat_onReceived)>();
		});

		batch.add("Net::NetworkEngine::sendUnreliableCore", "F0 4F 2D E9 00 40 A0 E1 01 0B 80 E2 01 50 A0 E1", [this](memory::handle handle)
		{
			m_Net_NetworkEngine_sendUnreliableCore = handle.as<decltype(m_Net_NetworkEngine_sendUnreliableCore)>();
		});

		batch.add("Net::NetworkEventModule::calc", "F0 4F 2D E9 00 50 A0 E1 98 80 80 E2 0C D0 4D E2", [this](memory::handle handle)
		{
			m_Net_NetworkEventModule_calc_0xB4 = handle.add(0xB4).as<decltype(m_Net_NetworkEventModule_calc_0xB4)>();
		});

		batch.add("Net::NetworkFriendsManager::updateFriendInfo", "F8 40 2D E9 0A 4A 80 E2 00 50 A0 E1 29 4E 84 E2", [this](memory::handle handle)
		{
			m_Net_NetworkFriendsManager_updateFriendInfo = handle.as<decltype(m_Net_NetworkFriendsManager_updateFriendInfo)>();
		});

		batch.add("Net::NetworkGameMgr::requestGoal", "F8 30 9F E5 30 00 2D E9 00 00 51 E3 00 C0 93 E5", [this](memory::handle handle)
		{
			m_Net_NetworkGameMgr_requestGoal_0x4 = handle.add(0x4).as<decltype(m_Net_NetworkGameMgr_requestGoal_0x4)>();
		});

		batch.add("Net::NetworkItemSlotMgr::Buffer::setEquipItemType", "00 00 51 E3 04 40 2D E5 3B 00 00 BA F0 C0 9F E5", [this](memory::handle handle)
		{
			m_Net_NetworkItemSlotMgr_Buffer_setEquipItemType = handle.as<decltype(m_Net_NetworkItemSlotMgr_Buffer_setEquipItemType)>();
		});

		batch.add("RaceSys::LapRankChecker::calcLapPosition_", "F0 4F 2D E9 01 40 A0 E1 00 50 A0 E1 02 8B 2D ED", [this](memory::handle handle)
		{
			m_RaceSys_LapRankChecker_calcLapPosition = handle.as<decltype(m_RaceSys_LapRankChecker_calcLapPosition)>();
		});

		batch.add("RaceSys::ModeManagerRace::calcCountDown", "70 40 2D E9 00 40 A0 E1 B0 50 9F E5 00 60 A0 E3", [this](memory::handle handle)
		{
			m_RaceSys_ModeManagerRace_calcCountDown_0x18 = handle.add(0x18).as<decltype(m_RaceSys_ModeManagerRace_calcCountDown_0x18)>();
		});

		batch.add("Sequence::BaseRacePage::sub_equipItem", "70 40 2D E9 01 40 A0 E1 10 00 54 E3 00 C0 A0 E1", [this](memory::handle handle)
		{
			m_Sequence_BaseRacePage_subEquipItem_0xAC = handle.add(0xAC).as<decltype(m_Sequence_BaseRacePage_subEquipItem_0xAC)>();
		});

		batch.add("System::KDPadInputer::calcInput", "04 10 90 E5 01 00 51 E3 02 00 00 1A 00 10 90 E5", [this](memory::handle handle)
		{
			m_System_KDPadInputer_calcInput = handle.as<decltype(m_System_KDPadInputer_calcInput)>();
		});
		
		batch.add("UI::MessageWriter::buildNumString", "F0 43 2D E9 01 50 A0 E1 0C D0 4D E2", [this](memory::handle handle)
		{
			m_UI_MessageWriter_buildNumString_0x8 = handle.add(0x8).as<decltype(m_UI_MessageWriter_buildNumString_0x8)>();
			m_UI_MessageWriter_buildNumString_0x11C = handle.add(0x11C).as<decltype(m_UI_MessageWriter_buildNumString_0x11C)>();
			m_UI_MessageWriter_buildNumString_0x124 = handle.add(0x124).as<decltype(m_UI_MessageWriter_buildNumString_0x124)>();
		});

		batch.add("UI::RaceItemBoxControl::onCalc", "F0 47 2D E9 00 40 A0 E1 00 50 A0 E3 02 8B 2D ED", [this](memory::handle handle)
		{
			m_UI_RaceItemBoxControl_onCalc_0x254 = handle.add(0x254).as<decltype(m_UI_RaceItemBoxControl_onCalc_0x254)>();
		});
		
		batch.add("NetworkBufferSizes", "01 80 88 E2 08 00 50 E1 ? ? ? CA F0 9F BD E8", [this](memory::handle handle)
		{
			m_network_buffer_sizes = *handle.add(0x10).as<decltype(m_network_buffer_sizes) *>();
		});

		batch.add("Data", "F0 4F 2D E9 01 6A 80 E2 00 40 A0 E1 04 8B 2D ED", [this](memory::handle handle)
		{
			auto hnd = memory::handle(*handle.add(0x410).as<void **>());
			
			m_miniturbo_blue_threshold = hnd.add(0x12C).as<decltype(m_miniturbo_blue_threshold)>();
			m_miniturbo_red_threshold = hnd.add(0x130).as<decltype(m_miniturbo_red_threshold)>();
			m_invincibility_frames_invisible_amount = hnd.add(0x230).as<decltype(m_invincibility_frames_invisible_amount)>();
			m_invincibility_frames_visible_amount = hnd.add(0x234).as<decltype(m_invincibility_frames_visible_amount)>();
			m_press_frames_kart_size = hnd.add(0x2CC).as<decltype(m_press_frames_kart_size)>();
		});
		
		batch.run(memory::ranges::c_text);

		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}
