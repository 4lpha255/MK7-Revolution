#include <base/services/rainbow_service.hpp>

#include <base/settings.hpp>

#include <math.h>

namespace base
{
    rainbow_service::rainbow_service()
    :
        m_hue(0.f)
    {
        g_rainbow_service = this;
    }

    rainbow_service::~rainbow_service()
    {
        g_rainbow_service = nullptr;
    }

    void rainbow_service::run()
    {
        m_hue += g_settings.m_options.base.rainbow.hue_amount;
    }

    rainbow_service::rgb rainbow_service::get_color()
    {
        return hsv{ m_hue, g_settings.m_options.base.rainbow.saturation, g_settings.m_options.base.rainbow.value }.to_rgb();
    }

    CTRPluginFramework::Color rainbow_service::get_ctrpf_color()
    {
        return get_color().as_u32();
    }

    sead::Color4f rainbow_service::get_sead_color()
    {
        auto const color = get_color();
        return { color.r.v, color.g.v, color.b.v, 1.f };
    }

    u8 rainbow_service::component::as_u8()
    {
        return static_cast<u8>(v * std::numeric_limits<u8>::max());
    }

    u32 rainbow_service::rgb::as_u32()
    {
        return (r.as_u8() << 24) | (g.as_u8() << 16) | (b.as_u8() << 8) | std::numeric_limits<u8>::max();
    }
    
    rainbow_service::rgb rainbow_service::hsv::to_rgb()
    {
        if (s.v == 0.f)
            return { v, v, v };

        auto result = rgb{};

        h.v = std::fmod(h.v, 1.f) / (60.f / 360.f);
        auto i = static_cast<int>(h.v);
        auto f = h.v - static_cast<float>(i);
        auto p = v.v * (1.f - s.v);
        auto q = v.v * (1.f - s.v * f);
        auto t = v.v * (1.f - s.v * (1.f - f));

        switch (i)
        {
            case 0: result.r.v = v.v; result.g.v = t; result.b.v = p; break;
            case 1: result.r.v = q; result.g.v = v.v; result.b.v = p; break;
            case 2: result.r.v = p; result.g.v = v.v; result.b.v = t; break;
            case 3: result.r.v = p; result.g.v = q; result.b.v = v.v; break;
            case 4: result.r.v = t; result.g.v = p; result.b.v = v.v; break;
            case 5: default: result.r.v = v.v; result.g.v = p; result.b.v = q; break;
        }

        return result;
    }
}