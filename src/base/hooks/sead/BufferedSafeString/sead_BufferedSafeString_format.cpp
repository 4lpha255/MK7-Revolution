#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    s32 hooks::sead_BufferedSafeString_format(sead::BufferedSafeString *_this, char const *fmt, ...)
    {
        features::item::item_model(fmt);

        auto args = va_list{};
        va_start(args, fmt);
        auto const ret = _this->formatV(fmt, args);
        va_end(args);

        return ret;
    }
}