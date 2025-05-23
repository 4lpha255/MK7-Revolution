#include <base/entries.hpp>

#include <base/settings.hpp>

#include <magic_enum/magic_enum_all.hpp>

#include <format>

namespace base
{
	void entries::kart::instant_miniturbo_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

		auto &instant_miniturbo = g_settings.m_options.kart.instant_miniturbo;

		while (true)
		{
			keyboard.Populate(std::vector<std::string>
			{
				std::format("Type ({})", magic_enum::enum_name(instant_miniturbo.type))
			});

			auto const choice = keyboard.Open();
			if (choice < 0)
				break;

			switch (choice)
			{
				case 0: instant_miniturbo.type = magic_enum::enum_next_value_circular(instant_miniturbo.type); break;
			}
		}
	}
}