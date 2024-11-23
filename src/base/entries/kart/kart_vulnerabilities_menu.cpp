#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum.hpp>

#include <format>

namespace base
{
    void entries::kart::kart_vulnerabilities_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

        auto &kart_vulnerabilities = g_settings.m_options.kart.kart_vulnerabilities;

        while (true)
		{
            auto options = std::vector<std::string>();
            std::for_each(kart_vulnerabilities.toggles.begin(), kart_vulnerabilities.toggles.end(), [&](auto const &e) { options.push_back(std::format("{} ({})", magic_enum::enum_name(e.first), menu::toggle_name(e.second))); });
            keyboard.Populate(options);

			auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            auto const &toggle = std::next(kart_vulnerabilities.toggles.begin(), choice);
            toggle->second ^= true;
        }
    }
}