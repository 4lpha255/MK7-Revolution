#pragma once

#include <CTRPluginFramework.hpp>

#include <map>

namespace base
{
    class menu
    {
        using entries_t = std::vector<CTRPluginFramework::MenuEntry *>;

    public:
		explicit menu();
		~menu();

        void run();

        [[nodiscard]] entries_t get_all_entries();
        [[nodiscard]] entries_t get_feature_entries();

    private:
        friend struct entries;
        friend class features;
        
        void create();
        void finalize();

        void update_colors();
        void update_counter();

        inline void push_entry_list(entries_t &, entries_t const &);
        void parse_folder(entries_t &, CTRPluginFramework::MenuFolder const &);

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
        CTRPluginFramework::MenuEntry *m_item_selfstrike_entry;
        CTRPluginFramework::MenuEntry *m_item_drop_entry;
        CTRPluginFramework::MenuEntry *m_item_hang_entry;
        CTRPluginFramework::MenuEntry *m_item_rain_entry;
        CTRPluginFramework::MenuEntry *m_item_terrain_entry;
        CTRPluginFramework::MenuEntry *m_item_limiters_entry;
        CTRPluginFramework::MenuEntry *m_disable_item_clear_entry;
        CTRPluginFramework::MenuEntry *m_zero_gravity_shells_entry;
        CTRPluginFramework::MenuEntry *m_rainbow_shell_stripes_entry;
        CTRPluginFramework::MenuEntry *m_blue_shell_battle_crash_fix_entry;

        // Kart
        CTRPluginFramework::MenuEntry *m_invincibility_entry;
        CTRPluginFramework::MenuEntry *m_intangibility_entry;
        CTRPluginFramework::MenuEntry *m_kart_usage_entry;
        CTRPluginFramework::MenuEntry *m_kart_statuses_entry;
        CTRPluginFramework::MenuEntry *m_killer_control_entry;
        CTRPluginFramework::MenuEntry *m_future_fly_entry;
        CTRPluginFramework::MenuEntry *m_instant_acceleration_entry;
        CTRPluginFramework::MenuEntry *m_instant_respawn_entry;
        CTRPluginFramework::MenuEntry *m_instant_miniturbo_entry;
        CTRPluginFramework::MenuEntry *m_kart_effect_color_modifier_entry;

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
        CTRPluginFramework::MenuEntry *m_goal_score_modifier_entry;
        CTRPluginFramework::MenuEntry *m_mii_matching_viewer_entry;
        CTRPluginFramework::MenuEntry *m_force_replacement_entry;
        CTRPluginFramework::MenuEntry *m_protections_entry;
        CTRPluginFramework::MenuEntry *m_vr_extender_fix_entry;

        // System
        CTRPluginFramework::MenuEntry *m_save_data_modifier_entry;

        // UI
        CTRPluginFramework::MenuEntry *m_enhanced_minimap_entry;
        CTRPluginFramework::MenuEntry *m_mii_heads_entry;

        // Base
        CTRPluginFramework::MenuEntry *m_disable_features_entry;
        CTRPluginFramework::MenuEntry *m_reset_settings_entry;
        CTRPluginFramework::MenuEntry *m_rainbow_entry;

        CTRPluginFramework::MenuEntry *m_enabled_features_entry;
    };

    inline menu *g_menu{};
}