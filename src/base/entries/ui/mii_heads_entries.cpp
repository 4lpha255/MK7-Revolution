#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/patches.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::ui::mii_heads::game(CTRPluginFramework::MenuEntry *entry)
    {
        if (entry->WasJustActivated())
        {
            auto const &mii_heads = g_settings.m_options.ui.mii_heads;

            g_patches->m_Mii_MiiEngine_createMiiFace_0x128_patch.enable();
            g_patches->m_Mii_MiiEngine_createMiiFace_0x168_patch.enable();

            if (mii_heads.map)
                g_patches->m_Sequence_BaseRacePage_initMapIcon_0x584_patch.enable();
            if (mii_heads.mii_bar)
                g_patches->m_set_bar_tex_worldwide_0x18_patch.enable();
            if (mii_heads.rank_board)
                g_patches->m_Sequence_BaseRacePage_initRankBoard_0x7A8_patch.enable();
            if (mii_heads.results)
                g_patches->m_Sequence_RacePage_resEnter_0xD0_patch.enable();
        }
        else if (!entry->IsActivated())
        {
            g_patches->m_Sequence_RacePage_resEnter_0xD0_patch.disable();
            g_patches->m_Sequence_BaseRacePage_initRankBoard_0x7A8_patch.disable();
            g_patches->m_set_bar_tex_worldwide_0x18_patch.disable();
            g_patches->m_Sequence_BaseRacePage_initMapIcon_0x584_patch.disable();

            g_patches->m_Mii_MiiEngine_createMiiFace_0x168_patch.disable();
            g_patches->m_Mii_MiiEngine_createMiiFace_0x128_patch.disable();
        }
    }

    void entries::ui::mii_heads::menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto &mii_heads = g_settings.m_options.ui.mii_heads;

        while (true)
        {
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Map ({})", menu::toggle_name(mii_heads.map)),
                std::format("MiiBar ({})", menu::toggle_name(mii_heads.mii_bar)),
                std::format("RankBoard ({})", menu::toggle_name(mii_heads.rank_board)),
                std::format("Results ({})", menu::toggle_name(mii_heads.results)),
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
                mii_heads.mii_bar ^= true;
                g_patches->m_set_bar_tex_worldwide_0x18_patch.set(mii_heads.mii_bar);
                break;
            case 2:
                mii_heads.rank_board ^= true;
                g_patches->m_Sequence_BaseRacePage_initRankBoard_0x7A8_patch.set(mii_heads.rank_board);
                break;
            case 3:
                mii_heads.results ^= true;
                g_patches->m_Sequence_RacePage_resEnter_0xD0_patch.set(mii_heads.results);
                break;
            }
        }
    }
}