#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
	void entries::kart::intangibility_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

		auto &intangibility = g_settings.m_options.kart.intangibility;

		while (true)
		{
			keyboard.Populate(std::vector<std::string>
			{
				std::format("Invert ({})", menu::s_toggles[intangibility.invert])
			});

			auto const choice = keyboard.Open();
            if (choice < 0)
                break;

			switch (choice)
			{
				case 0: intangibility.invert ^= true; break;
			}
		}
	}
}