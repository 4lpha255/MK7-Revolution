#pragma once

#include <CTRPluginFramework.hpp>

namespace base
{
    class rainbow_service
    {
    public:
        explicit rainbow_service();
        ~rainbow_service();

        void run();

        CTRPluginFramework::Color get();

    private:
        struct rgb
        {
            float r, g, b;

            u32 as_u32();
        };

        struct hsv
        {
            float h, s, v;

            rgb to_rgb();
        };

        float m_hue;
    };

    inline rainbow_service *g_rainbow_service{};
}