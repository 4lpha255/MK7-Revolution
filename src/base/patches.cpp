#include <base/patches.hpp>

#include <base/pointers.hpp>

namespace base
{
    patches::patches()
    :
        m_Mii_MiiEngine_createMiiFace_0x128_patch(g_pointers->m_Mii_MiiEngine_createMiiFace_0x128, { 0xE3A00009 }), /* mov r0, #9 */
        m_Mii_MiiEngine_createMiiFace_0x168_patch(g_pointers->m_Mii_MiiEngine_createMiiFace_0x168, { 0xE3A00009 }), /* mov r0, #9 */
        m_Sequence_BaseRacePage_drawItemIcon_0x44_patch(g_pointers->m_Sequence_BaseRacePage_drawItemIcon_0x44, { 0xE320F000 }), /* nop */
        m_Sequence_BaseRacePage_drawItemIcon_0x28C_patch(g_pointers->m_Sequence_BaseRacePage_drawItemIcon_0x28C, { 0xE320F000 }), /* nop */
        m_Sequence_BaseRacePage_initMapIcon_0x584_patch(g_pointers->m_Sequence_BaseRacePage_initMapIcon_0x584, { 0xE3A00009 }), /* mov r0, #9 */
        m_Sequence_BaseRacePage_initRankBoard_0x7A8_patch(g_pointers->m_Sequence_BaseRacePage_initRankBoard_0x7A8, { 0xE3A06009 }), /* mov r6, #9 */
        m_Sequence_RacePage_resEnter_0xD0_patch(g_pointers->m_Sequence_RacePage_resEnter_0xD0, { 0xE3A0B009 }), /* mov r11, #9 */
        m_UI_MessageWriter_buildNumString_0x8_patch(g_pointers->m_UI_MessageWriter_buildNumString_0x8, { 0xE24DD024 }), /* sub sp, sp, #0x24 */
        m_UI_MessageWriter_buildNumString_0x11C_patch(g_pointers->m_UI_MessageWriter_buildNumString_0x11C, { 0xE28DD024 }), /* add sp, sp, #0x24 */
		m_UI_MessageWriter_buildNumString_0x124_patch(g_pointers->m_UI_MessageWriter_buildNumString_0x124, { UINT32_MAX }), /* 0xFFFFFFFF */
        m_set_bar_tex_worldwide_0x18_patch(g_pointers->m_set_bar_tex_worldwide_0x18, { 0xEA000004 }) /* b #0x18 */
    {
        g_patches = this;
    }

    patches::~patches()
    {
        g_patches = nullptr;
    }
}