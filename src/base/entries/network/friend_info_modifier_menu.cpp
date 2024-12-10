#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum_all.hpp>

#include <format>

namespace base
{
    void entries::network::friend_info_modifier_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(true);

        auto const categories = std::vector<std::string>({ "Principal ID" });

        auto &friend_info_modifier = g_settings.m_options.network.friend_info_modifier;

        while (true)
		{
            keyboard.GetMessage() = entry->Name();
            keyboard.Populate(categories);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            auto const &category = categories.at(choice);

            switch (choice)
            {
                case 0:
                {
                    while (true)
		            {
                        keyboard.GetMessage() = std::format("{}\n{}", entry->Name(), category);
                        auto options = std::vector<std::string>
                        {
                            std::format("Enabled ({})", menu::toggle_name(friend_info_modifier.principal_id.enabled)),
                            std::format("Notify ({})", menu::toggle_name(friend_info_modifier.principal_id.notify)),
                            std::format("Mode ({})", magic_enum::enum_name(friend_info_modifier.principal_id.mode))
                        };
                        if (friend_info_modifier.principal_id.mode == decltype(friend_info_modifier.principal_id.mode)::Value)
                            options.push_back(std::format("Value ({:X})", friend_info_modifier.principal_id.value));
                        keyboard.Populate(options);

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: friend_info_modifier.principal_id.enabled ^= true; break;
                            case 1: friend_info_modifier.principal_id.notify ^= true; break;
                            case 2: friend_info_modifier.principal_id.mode = magic_enum::enum_next_value_circular(friend_info_modifier.principal_id.mode); break;
                            case 3: keyboard.Open(friend_info_modifier.principal_id.value, friend_info_modifier.principal_id.value); break;
                        }
                    }

                    break;
                }
            }
        }
    }
}