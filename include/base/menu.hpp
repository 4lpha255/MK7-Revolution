#pragma once

#include <CTRPluginFramework.hpp>

#include <map>

namespace base
{
    class menu
    {
    public:
		explicit menu();
		~menu();

        void run();

    private:
        friend struct entries;
        friend class features;
        
        void create();
        void finalize();

        inline static std::map<bool, std::string> s_toggles =
        {
            { false, (CTRPluginFramework::Color(255, 0, 0) << "OFF") + (CTRPluginFramework::Color::White << "") },
            { true, (CTRPluginFramework::Color(0, 255, 0) << "ON") + (CTRPluginFramework::Color::White << "") }
        };

        CTRPluginFramework::PluginMenu *m_plugin_menu;

        // Item
        CTRPluginFramework::MenuEntry *m_item_wheel_entry;
        CTRPluginFramework::MenuEntry *m_item_rapidfire_entry;
        CTRPluginFramework::MenuEntry *m_item_usage_entry;
        CTRPluginFramework::MenuEntry *m_item_drop_entry;
        CTRPluginFramework::MenuEntry *m_item_hang_entry;
        CTRPluginFramework::MenuEntry *m_item_rain_entry;
        CTRPluginFramework::MenuEntry *m_item_limiters_entry;
        CTRPluginFramework::MenuEntry *m_zero_gravity_shells_entry;
        CTRPluginFramework::MenuEntry *m_rainbow_shell_stripes_entry;
        CTRPluginFramework::MenuEntry *m_blue_shell_battle_crash_fix_entry;

        // Kart
        CTRPluginFramework::MenuEntry *m_invincibility_entry;
        CTRPluginFramework::MenuEntry *m_intangibility_entry;
        CTRPluginFramework::MenuEntry *m_kart_usage_entry;
        CTRPluginFramework::MenuEntry *m_kart_statuses_entry;
        CTRPluginFramework::MenuEntry *m_killer_control_entry;
        CTRPluginFramework::MenuEntry *m_instant_respawn_entry;
        CTRPluginFramework::MenuEntry *m_instant_miniturbo_entry;

        // Mode
        CTRPluginFramework::MenuEntry *m_drive_during_sync_entry;
        CTRPluginFramework::MenuEntry *m_trigger_respawn_entry;
        CTRPluginFramework::MenuEntry *m_stalking_entry;

        // Network
        CTRPluginFramework::MenuEntry *m_kart_warp_entry;
        CTRPluginFramework::MenuEntry *m_disable_killer_lag_entry;
        CTRPluginFramework::MenuEntry *m_item_delimiters_entry;
        CTRPluginFramework::MenuEntry *m_high_data_rate_entry;
        CTRPluginFramework::MenuEntry *m_invisibility_entry;
        CTRPluginFramework::MenuEntry *m_disable_idle_disconnect_entry;
        CTRPluginFramework::MenuEntry *m_instant_disconnect_entry;
        CTRPluginFramework::MenuEntry *m_event_frame_modifier_entry;
        CTRPluginFramework::MenuEntry *m_friend_info_modifier_entry;
        CTRPluginFramework::MenuEntry *m_mii_matching_viewer_entry;
        CTRPluginFramework::MenuEntry *m_force_replacement_entry;
        CTRPluginFramework::MenuEntry *m_protections_entry;

        // Base
        CTRPluginFramework::MenuEntry *m_rainbow_entry;
    };

    inline menu *g_menu{};
}