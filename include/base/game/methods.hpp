#pragma once

#include <forward.hpp>

#include <Item/eItemSlot.hpp>
#include <Kart/EJugemRecoverType.hpp>

#include <math/seadVectorFwd.h>

namespace base::game::methods
{
	using operator_new_t = void *(*)(size_t count);
	using Item_ItemDirector_dropEquip_t = void (*)(Item::ItemDirector *_this, s32 player_id);
	using Item_ItemObjBase_stateEquipHang_t = void (*)(Item::ItemObjBase *_this);
	using Item_ItemObjDirectorBase_emitItemImpl_t = void (*)(Item::ItemObjDirectorBase *_this, s32 player_id, sead::Vector3f const *position, sead::Vector3f const *velocity);
	using Item_ItemObjDirectorBase_entryUse_t = Item::ItemObjBase *(*)(Item::ItemObjDirectorBase *_this, Kart::InfoProxy *info_proxy, bool on_self);
	using Item_KartItem_setItemForce_t = void (*)(Item::KartItem *_this, Item::eItemSlot item);
	using Kart_Unit_startJugemRecover_t = void (*)(Kart::Unit *_this, Kart::EJugemRecoverType type);
	using Kart_VehicleMove_endKiller_t = void (*)(Kart::VehicleMove *_this);
}