#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <base/services/message_service.hpp>

#include <format>

namespace base
{
    void entries::network::goal_score_modifier_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
        
        auto &goal_score_modifier = g_settings.m_options.network.goal_score_modifier;

        while (true)
		{
            keyboard.GetMessage() = entry->Name();
            keyboard.Populate(std::vector<std::string>
            {
                std::format("{} ({}, {})", g_message_service->get("Menu", LMS_MessageID::Race), menu::s_toggles[goal_score_modifier.race.enabled], magic_enum::enum_name(goal_score_modifier.race.mode)),
                std::format("{} ({}, {})", g_message_service->get("Menu", LMS_MessageID::Battle), menu::s_toggles[goal_score_modifier.battle.enabled], magic_enum::enum_name(goal_score_modifier.battle.mode))
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            keyboard.GetMessage() = entry->Name() + "\n" + g_message_service->get("Menu", choice == 0 ? LMS_MessageID::Race : LMS_MessageID::Battle);
            
            auto &type = choice == 0 ? goal_score_modifier.race : goal_score_modifier.battle;

            while (true)
            {
                keyboard.Populate(std::vector<std::string>
                {
                    std::format("Enabled ({})", menu::s_toggles[type.enabled]),
                    std::format("Mode ({})", magic_enum::enum_name(type.mode))
                });

                auto const choice = keyboard.Open();
                if (choice < 0)
                    break;

                switch (choice)
                {
                    case 0: type.enabled ^= true; break;
                    case 1: utils::enum_next(type.mode); break;
                }
            }
        }
    }
}