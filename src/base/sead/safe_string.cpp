#include <base/sead/safe_string.hpp>

#include <base/pointers.hpp>

namespace base::_sead
{
    safe_string::safe_string(char const *str) : sead::SafeString(str)
    {
        // Fix game object checks not working
        *reinterpret_cast<void **>(this) = g_pointers->m_sead_SafeString_vtbl;
    }
}