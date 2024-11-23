#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
	void hooks::Kart_VehicleReact_calcReact_0x4C()
	{
		asm volatile
		(
			"push {lr}\n"
			"mov r0, r4\n"
			"bl __kart_vulnerabilities_killer\n"
			"pop {pc}\n"
		);
	}

	extern "C" auto __kart_vulnerabilities_killer(Kart::VehicleReact *_this)
	{
		return base::features::kart::kart_vulnerabilities::killer(_this);
	}
}