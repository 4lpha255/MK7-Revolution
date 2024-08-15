#pragma once

#include "memory/patch.hpp"

namespace base
{
    class patches
    {
    public:
        explicit patches();
        ~patches();
    };

    inline patches *g_patches{};
}