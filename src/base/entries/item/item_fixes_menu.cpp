#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/patches.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <base/services/message_service.hpp>

#include <format>

namespace base
{
    void entries::item::item_fixes_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto &item_fixes = g_settings.m_options.item.item_fixes;

        while (true)
        {
            keyboard.Populate(std::vector<std::string>
            {
                std::format("{} {} Respawn ({})", utils::item_name(Item::eItemType::KouraB), g_message_service->get(LMS_MessageID::Battle), menu::toggle_name(item_fixes.blue_shell_battle_respawn)),
                std::format("Preview Minimap Explosion ({})", menu::toggle_name(item_fixes.preview_minimap_explosion)),
                std::format("{} Acceleration ({})", utils::item_name(Item::eItemType::Star), menu::toggle_name(item_fixes.star_acceleration)),
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: item_fixes.blue_shell_battle_respawn ^= true; break;
                case 1: item_fixes.preview_minimap_explosion ^= true; break;
                case 2: item_fixes.star_acceleration ^= true; break;
            }
        }
    }
}