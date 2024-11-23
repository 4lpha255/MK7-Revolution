#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Kart/VehicleReact.hpp>

namespace base
{
    std::optional<s32> features::kart::kart_vulnerabilities::blink_before(Kart::VehicleReact *_this)
    {
        using status = settings::options::kart::kart_vulnerabilities::status;

        if (g_menu->m_kart_vulnerabilities_entry->IsActivated() && _this->m_is_master && !_this->m_is_net_recv && g_settings.m_options.kart.kart_vulnerabilities.toggles.at(status::Blink))
        {
            auto const original = _this->m_invincibility_frames;
            _this->m_invincibility_frames = {};
            return original;
        }

        return {};
    }

    void features::kart::kart_vulnerabilities::blink_after(Kart::VehicleReact *_this, std::optional<s32> original)
    {
        if (original.has_value())
            _this->m_invincibility_frames = original.value();
    }
}