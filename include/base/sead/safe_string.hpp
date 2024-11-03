#pragma once

#include <prim/seadSafeString.h>

namespace base::_sead
{
    class safe_string : public sead::SafeString
    {
    public:
        safe_string(char const *str);

        using sead::SafeString::operator=;
    };
};