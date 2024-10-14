#pragma once

#include <Kart/Unit.hpp>

namespace base::game::kart
{
    class unit : public Kart::Unit
    {
    public:
        struct
        {
            size_t index;
            bool changed;
        }
        m_stalking;
    };
    static_assert(sizeof(unit) == 0x408);
}