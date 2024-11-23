#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
	bool hooks::Kart_VehicleReact_reactAccidentCommon(Kart::VehicleReact *_this, Kart::VehicleReact::ECallType call_type, int unk1, int unk2, Kart::VehicleReact::EAcdType acd_type, sead::Vector3f *unk3, sead::Vector3f *unk4)
	{
		if (features::kart::invincibility::calc(_this))
			return false;

		auto const blink = features::kart::kart_vulnerabilities::blink_before(_this);

		auto const result = g_hooking->m_Kart_VehicleReact_reactAccidentCommon_hook.call_original<bool>(_this, call_type, unk1, unk2, acd_type, unk3, unk4);

		features::kart::kart_vulnerabilities::blink_after(_this, blink);

		return result;
	}

	void hooks::Kart_VehicleReact_reactAccidentCommon_0x98()
    {
        asm volatile
        (
            "push {lr}\n"
            "mov r0, r4\n"
            "bl __kart_vulnerabilities_star\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __kart_vulnerabilities_star(Kart::VehicleReact *_this)
    {
        return features::kart::kart_vulnerabilities::star(_this);
    }

    void hooks::Kart_VehicleReact_reactAccidentCommon_0xAC()
    {
        asm volatile
        (
            "push {lr}\n"
            "mov r0, r4\n"
            "bl __kart_vulnerabilities_statuses\n"
            "pop {pc}\n"
        );
    }

    extern "C" auto __kart_vulnerabilities_statuses(Kart::VehicleReact *_this)
    {
        return features::kart::kart_vulnerabilities::statuses(_this);
    }
}