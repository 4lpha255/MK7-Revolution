#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/patches.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum_all.hpp>

#include <format>

namespace base
{
    void entries::ui::enhanced_minimap::game(CTRPluginFramework::MenuEntry *entry)
    {
        if (entry->WasJustActivated())
        {
            if (g_settings.m_options.ui.enhanced_minimap.extended_minimap_items)
            {
                g_patches->m_Sequence_BaseRacePage_drawItemIcon_0x44_patch.enable();
                g_patches->m_Sequence_BaseRacePage_drawItemIcon_0x28C_patch.enable();
            }
        }
        else if (!entry->IsActivated())
        {
            g_patches->m_Sequence_BaseRacePage_drawItemIcon_0x28C_patch.disable();
            g_patches->m_Sequence_BaseRacePage_drawItemIcon_0x44_patch.disable();
        }
    }

    void entries::ui::enhanced_minimap::menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto &enhanced_minimap = g_settings.m_options.ui.enhanced_minimap;

        while (true)
        {
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Extended Minimap Items ({})", menu::toggle_name(enhanced_minimap.extended_minimap_items)),
                std::format("Directed Heads ({})", menu::toggle_name(enhanced_minimap.directed_heads)),
                std::format("Battle Zoom ({})", magic_enum::enum_name(enhanced_minimap.battle_zoom))
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0:
                {
                    enhanced_minimap.extended_minimap_items ^= true;
                    g_patches->m_Sequence_BaseRacePage_drawItemIcon_0x44_patch.set(enhanced_minimap.extended_minimap_items);
                    g_patches->m_Sequence_BaseRacePage_drawItemIcon_0x28C_patch.set(enhanced_minimap.extended_minimap_items);
                    break;
                }
                case 1: enhanced_minimap.directed_heads ^= true; break;
                case 2: enhanced_minimap.battle_zoom = magic_enum::enum_next_value_circular(enhanced_minimap.battle_zoom); break;
            }
        }
    }
}