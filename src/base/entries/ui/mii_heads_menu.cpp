#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/patches.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::ui::mii_heads_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto &mii_heads = g_settings.m_options.ui.mii_heads;

        while (true)
        {
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Map ({})", menu::s_toggles[mii_heads.map]),
                std::format("RankBoard ({})", menu::s_toggles[mii_heads.rank_board]),
                std::format("Results ({})", menu::s_toggles[mii_heads.results]),
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
            case 0:
                mii_heads.map ^= true;
                g_patches->m_Sequence_BaseRacePage_initMapIcon_0x584_patch.set(mii_heads.map);
                break;
            case 1:
                mii_heads.rank_board ^= true;
                g_patches->m_Sequence_BaseRacePage_initRankBoard_0x7A8_patch.set(mii_heads.rank_board);
                break;
            case 2:
                mii_heads.results ^= true;
                g_patches->m_Sequence_RacePage_resEnter_0xD0_patch.set(mii_heads.results);
                break;
            }
        }
    }
}