#include <base/patches.hpp>

namespace base
{
    patches::patches()
    {
        g_patches = this;
    }

    patches::~patches()
    {
        g_patches = nullptr;
    }
}