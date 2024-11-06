#include <prim/seadStringUtil.h>

#include <cstdio>

namespace sead::StringUtil
{
    s32 vsnprintf(char *s, size_t n, char const *format, va_list args)
    {
        return std::vsnprintf(s, n, format, args);
    }
}