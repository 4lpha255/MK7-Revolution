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

        memory::patch<u32> m_UI_MessageWriter_buildNumString_0x8_patch;
        memory::patch<u32> m_UI_MessageWriter_buildNumString_0x11C_patch;
		memory::patch<u32> m_UI_MessageWriter_buildNumString_0x124_patch;
    };

    inline patches *g_patches{};
}