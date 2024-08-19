#include <base/patches.hpp>

#include <base/pointers.hpp>

namespace base
{
    patches::patches()
    :
        m_UI_MessageWriter_buildNumString_0x8_patch(g_pointers->m_UI_MessageWriter_buildNumString_0x8, { 0xE24DD024 }), /* sub sp, sp, #0x24 */
        m_UI_MessageWriter_buildNumString_0x11C_patch(g_pointers->m_UI_MessageWriter_buildNumString_0x11C, { 0xE28DD024 }), /* add sp, sp, #0x24 */
		m_UI_MessageWriter_buildNumString_0x124_patch(g_pointers->m_UI_MessageWriter_buildNumString_0x124, { UINT32_MAX }) /* 0xFFFFFFFF */
    {
        g_patches = this;
    }

    patches::~patches()
    {
        g_patches = nullptr;
    }
}