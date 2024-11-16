#include <base/entries.hpp>

#include <base/patches.hpp>
#include <base/settings.hpp>

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
}