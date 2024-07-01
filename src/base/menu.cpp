#include <base/menu.hpp>

#include <base/entries.hpp>
#include <base/hooking.hpp>
#include <base/settings.hpp>

#include <base/services/rainbow_service.hpp>

#define DEFAULT_ENTRY [](MenuEntry *) {}

namespace base
{
    using namespace CTRPluginFramework;
    
    menu::menu()
    :
        m_plugin_menu(new PluginMenu(NAME, MAJOR_VERSION, MINOR_VERSION, REVISION_VERSION, ABOUT)),

        m_rainbow_entry(new MenuEntry("Rainbow", entries::base::rainbow_game, entries::base::rainbow_menu))
    {
        m_plugin_menu->SynchronizeWithFrame(true);
        m_plugin_menu->ShowWelcomeMessage(false);
        m_plugin_menu->OnNewFrame = [](Time)
        {
            if (g_menu->m_rainbow_entry->IsActivated())
            {
                g_rainbow_service->run();
                g_menu->m_plugin_menu->Title() = g_rainbow_service->get() << NAME;
            }
            else
            {
                g_menu->m_plugin_menu->Title() = NAME;
            }
        };
        m_plugin_menu->OnClosing = []() { g_settings.store(); };

        create();
        finalize();

        g_menu = this;
    }

    menu::~menu()
    {
        g_menu = nullptr;

        delete m_plugin_menu;
    }

    void menu::run()
    {
        m_plugin_menu->Run();
    }

    void menu::create()
    {
#ifdef _DEBUG
        *m_plugin_menu += new MenuFolder
        (
            "Debug", 
            {
                new MenuEntry(g_hooking->is_enabled() ? "Disable hooks" : "Enable hooks", nullptr, entries::debug::toggle_hooks_menu)
            }
        );
#endif

        if (auto base = new MenuFolder("Base"))
        {
            *base += m_rainbow_entry;

            *m_plugin_menu += base;
        }
    }

    void menu::finalize()
    {
        // Base
        m_rainbow_entry->Enable();
    }
}