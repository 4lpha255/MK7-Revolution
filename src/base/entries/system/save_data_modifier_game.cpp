#include <base/entries.hpp>

#include <base/pointers.hpp>

#include <base/services/message_service.hpp>

#include <System/SystemSaveData.hpp>

namespace base
{
    void entries::system::save_data_modifier_game(CTRPluginFramework::MenuEntry *entry)
    {
        if (g_pointers->m_system_save_data != nullptr)
        {
            auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
            keyboard.DisplayTopScreen = true;
            keyboard.IsHexadecimal(false);

            auto &data = g_pointers->m_system_save_data->m_player_flag_save_data;

            while (true)
            {
                keyboard.Populate(std::vector<std::string>
                {
                    std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::VR), data.m_flag_data.gp_vr.get_vr()),
                    std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::Wins), data.m_flag_data.wins),
                    std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::Losses), data.m_flag_data.losses),
                    std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::CoinsCollected), data.m_flag_data.coins),
                    std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::StreetPassTags), data.m_flag_data.streetpass_tags),
                });

                auto const choice = keyboard.Open();
                if (choice < 0)
                    break;

                switch (choice)
                {
                    case 0:
                    {
                        auto vr = data.m_flag_data.gp_vr.get_vr();
                        if (keyboard.Open(vr, vr) == 0)
                            data.m_flag_data.gp_vr.set_vr(vr);
                        break;
                    }
                    case 1: keyboard.Open(data.m_flag_data.wins, data.m_flag_data.wins); break;
                    case 2: keyboard.Open(data.m_flag_data.losses, data.m_flag_data.losses); break;
                    case 3: keyboard.Open(data.m_flag_data.coins, data.m_flag_data.coins); break;
                    case 4: keyboard.Open(data.m_flag_data.streetpass_tags, data.m_flag_data.streetpass_tags); break;
                }
            }
        }
    }
}