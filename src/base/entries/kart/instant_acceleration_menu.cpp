#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
	void entries::kart::instant_acceleration_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard();
		keyboard.DisplayTopScreen = true;

		auto &instant_acceleration = g_settings.m_options.kart.instant_acceleration;

		while (true)
		{
			keyboard.GetMessage() = entry->Name();
			keyboard.Populate(std::vector<std::string>
			{
				std::format("Stop ({})", menu::toggle_name(instant_acceleration.stop)),
				std::format("Custom ({}, {})", menu::toggle_name(instant_acceleration.custom.enabled), instant_acceleration.custom.value)
			});

			auto const choice = keyboard.Open();
			if (choice < 0)
				break;

			switch (choice)
			{
				case 0: instant_acceleration.stop ^= true; break;
				case 1:
				{
					keyboard.GetMessage() = entry->Name() + "\nCustom";

					while (true)
					{
						keyboard.Populate(std::vector<std::string>
						{
							std::format("Enabled ({})", menu::toggle_name(instant_acceleration.custom.enabled)),
							std::format("Value ({})", instant_acceleration.custom.value)
						});

						auto const choice = keyboard.Open();
						if (choice < 0)
							break;

						switch (choice)
						{
							case 0: instant_acceleration.custom.enabled ^= true; break;
							case 1: keyboard.Open(instant_acceleration.custom.value, instant_acceleration.custom.value); break;
						}
					}

					break;
				}
			}
		}
	}
}