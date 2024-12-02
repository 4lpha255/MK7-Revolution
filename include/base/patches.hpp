#pragma once

#include "types.hpp"

#include "memory/patch.hpp"

namespace base
{
    class patches
    {
    public:
        explicit patches();
        ~patches();

        memory::patch<u32> m_Item_ItemObjKouraG_calcStripe_0x34_patch;
		memory::patch<u32> m_Item_ItemObjKouraG_calcStripe_0xC4_patch;
        memory::patch<u32> m_Kart_Driver_calcApply_0x180_patch;
		memory::patch<u32> m_Kart_Driver_calcApply_0x1F4_patch;
		memory::patch<u32> m_Kart_Driver_calcApply_0x22C_patch;
        memory::patch<u32> m_Mii_MiiEngine_createMiiFace_0x128_patch;
        memory::patch<u32> m_Mii_MiiEngine_createMiiFace_0x168_patch;
        memory::patch<u32> m_Sequence_BaseRacePage_drawItemIcon_0x44_patch;
        memory::patch<u32> m_Sequence_BaseRacePage_drawItemIcon_0x28C_patch;
        memory::patch<u32> m_Sequence_BaseRacePage_initMapIcon_0x584_patch;
        memory::patch<u32> m_Sequence_BaseRacePage_initRankBoard_0x7A8_patch;
        memory::patch<u32> m_Sequence_RacePage_resEnter_0xD0_patch;
        memory::patch<u32> m_UI_MessageWriter_buildNumString_0x8_patch;
        memory::patch<u32> m_UI_MessageWriter_buildNumString_0x11C_patch;
	    memory::patch<u32> m_UI_MessageWriter_buildNumString_0x124_patch;
        memory::patch<u32> m_set_bar_tex_worldwide_0x18_patch;
        memory::patch<float> m_star_acceleration_patch;
    };

    inline patches *g_patches{};
}