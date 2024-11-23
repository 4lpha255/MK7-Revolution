#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::kart::future_fly_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;

        auto &future_fly = g_settings.m_options.kart.future_fly;

        while (true)
        {
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Pitch Keep ({})", menu::toggle_name(future_fly.pitch_keep)),
                std::format("Yaw Strength ({})", future_fly.yaw_strength),
                std::format("Pitch Limit ({})", future_fly.pitch_limit),
                std::format("Speed Forward ({})", future_fly.speed_forward),
                std::format("Speed Backward ({})", future_fly.speed_backward),
            });

            auto const choice = keyboard.Open();
			if (choice < 0)
				break;

            switch (choice)
			{
                case 0: future_fly.pitch_keep ^= true; break;
				case 1: keyboard.Open(future_fly.yaw_strength, future_fly.yaw_strength); break;
				case 2: keyboard.Open(future_fly.pitch_limit, future_fly.pitch_limit); break;
                case 3: keyboard.Open(future_fly.speed_forward, future_fly.speed_forward); break;
                case 4: keyboard.Open(future_fly.speed_backward, future_fly.speed_backward); break;
            }
        }
    }
}