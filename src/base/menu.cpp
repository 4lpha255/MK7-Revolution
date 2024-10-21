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
        m_plugin_menu(new PluginMenu(NAME, ABOUT)),

        m_disable_features_entry(new MenuEntry("Disable features", nullptr, entries::base::disable_features_game)),
        m_reset_settings_entry(new MenuEntry("Reset settings", nullptr, entries::base::reset_settings_game)),
        m_rainbow_entry(new MenuEntry("Rainbow", entries::base::rainbow_game, entries::base::rainbow_menu)),

        m_enabled_features_entry(new MenuEntry(""))
    {
        m_plugin_menu->SynchronizeWithFrame(true);
        m_plugin_menu->ShowWelcomeMessage(false);

        m_plugin_menu->OnNewFrame = [](Time)
        {
            g_menu->update_colors();
            g_menu->update_counter();
        };
        m_plugin_menu->OnClosing = []()
        {
            g_settings.store();
        };

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

    menu::entries_t menu::get_all_entries()
    {
        auto out = entries_t();

        push_entry_list(out, m_plugin_menu->GetEntryList());

        for (auto const &f : m_plugin_menu->GetFolderList())
            if (f != nullptr)
                parse_folder(out, *f);

        return out;
    }

    menu::entries_t menu::get_feature_entries()
    {
        auto out = get_all_entries();

        // Removes all entries that can't be checked
        std::erase_if(out, [](auto const *e) { return e->GetGameFunc() == nullptr; });

        std::erase(out, m_rainbow_entry);

        return out;
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
            *base += m_disable_features_entry;
            *base += m_reset_settings_entry;
            *base += m_rainbow_entry;

            *m_plugin_menu += base;
        }

        *m_plugin_menu += m_enabled_features_entry;
    }

    void menu::finalize()
    {
        // Base
        m_rainbow_entry->Enable();

        m_enabled_features_entry->CanBeSelected(false);
    }

    void menu::update_colors()
    {
        auto &settings = FwkSettings::Get();

        if (m_rainbow_entry->IsActivated())
        {
            g_rainbow_service->run();
            auto const color = g_rainbow_service->get_ctrpf_color();

            m_plugin_menu->Title() = color << NAME;
            settings.MenuSelectedItemColor = color;
        }
        else if (m_plugin_menu->Title() != NAME)
        {
            m_plugin_menu->Title() = NAME;
            settings.SetThemeDefault();
        }
    }

    void menu::update_counter()
    {
        auto const entries = get_feature_entries();
        auto const counter = std::count_if(entries.begin(), entries.end(), [](auto const *e) { return e->IsActivated(); });

        m_enabled_features_entry->Name() = std::format("Enabled features: {}/{}", counter, entries.size());
    }

    void menu::push_entry_list(entries_t &out, entries_t const &list)
    {
        for (auto const &e : list)
            if (e != nullptr)
                out.push_back(e);
    }

    void menu::parse_folder(entries_t &out, CTRPluginFramework::MenuFolder const &folder)
    {
        for (auto const &f : folder.GetFolderList())
            if (f != nullptr)
                parse_folder(out, *f);

        push_entry_list(out, folder.GetEntryList());
    }
}