#pragma once

#include <CTRPluginFramework.hpp>

namespace base
{
    class menu
    {
    public:
		explicit menu();
		~menu();

        void run();

    private:
        friend class features;
        
        void create();
        void finalize();

        CTRPluginFramework::PluginMenu *m_plugin_menu;

        // Base
        CTRPluginFramework::MenuEntry *m_rainbow_entry;
    };

    inline menu *g_menu{};
}