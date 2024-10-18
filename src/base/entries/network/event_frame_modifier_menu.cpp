#include <base/entries.hpp>

#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::network::event_frame_modifier_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(false);

        auto &event_frame_modifier = g_settings.m_options.network.event_frame_modifier;

        while (true)
		{
            keyboard.Populate(std::vector<std::string>
			{
				std::format("Value ({})", event_frame_modifier.value)
			});

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
			{
                case 0: keyboard.Open(event_frame_modifier.value, event_frame_modifier.value); break;
            }
        }
    }
}