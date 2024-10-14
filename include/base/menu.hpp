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

        // Base
        CTRPluginFramework::MenuEntry *m_disable_features_entry;
        CTRPluginFramework::MenuEntry *m_rainbow_entry;

        CTRPluginFramework::MenuEntry *m_enabled_features_entry;
    };

    inline menu *g_menu{};
}