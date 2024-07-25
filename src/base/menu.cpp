#include <base/menu.hpp>
#include <MenuEntryHelpers.hpp>

#include <base/menu_types.hpp>

#include <Item/eItemSlot.hpp>
#include <Item/eItemType.hpp>

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

        m_item_wheel_entry(new MenuEntry("Item Wheel", DEFAULT_ENTRY, entries::item::item_wheel_menu)),
        m_item_rapidfire_entry(new MenuEntry("Item Rapid-Fire", DEFAULT_ENTRY, entries::item::item_rapidfire_menu)),
        m_item_usage_entry(new MenuEntry("Item Usage", DEFAULT_ENTRY, entries::item::item_usage_menu)),
        m_item_drop_entry(new MenuEntry("Item Drop", DEFAULT_ENTRY, entries::item::item_drop_menu)),
        m_item_hang_entry(new MenuEntry("Item Hang", DEFAULT_ENTRY, entries::item::item_hang_menu)),
        m_item_rain_entry(new MenuEntry("Item Rain", DEFAULT_ENTRY, entries::item::item_rain_menu)),
        m_item_limiters_entry(new MenuEntry("Item Limiters", DEFAULT_ENTRY, entries::item::item_limiters_menu)),
        m_zero_gravity_shells_entry(new MenuEntry("Zero Gravity Shells", DEFAULT_ENTRY, entries::item::zero_gravity_shells_menu)),
        m_rainbow_shell_stripes_entry(new MenuEntry("Rainbow Shell Stripes", DEFAULT_ENTRY)),
        m_blue_shell_battle_crash_fix_entry(new MenuEntry("Blue Shell Battle Crash Fix", DEFAULT_ENTRY)),

        m_invincibility_entry(new MenuEntry("Invincibility", DEFAULT_ENTRY)),
        m_intangibility_entry(new MenuEntry("Intangibility", DEFAULT_ENTRY, entries::kart::intangibility_menu)),
        m_kart_statuses_entry(new MenuEntry("Kart Statuses", DEFAULT_ENTRY, entries::kart::kart_statuses_menu)),
        m_killer_control_entry(new MenuEntry("Killer Control", DEFAULT_ENTRY)),
        m_instant_respawn_entry(new MenuEntry("Instant Respawn", DEFAULT_ENTRY)),
        m_instant_miniturbo_entry(new MenuEntry("Instant Mini-Turbo", DEFAULT_ENTRY, entries::kart::instant_miniturbo_menu)),

        m_drive_during_sync_entry(new MenuEntry("Drive During Sync", DEFAULT_ENTRY)),
        m_trigger_respawn_entry(new MenuEntry("Trigger Respawn", DEFAULT_ENTRY)),

        m_kart_warp_entry(new MenuEntry("Kart Warp", DEFAULT_ENTRY)),
        m_item_delimiters_entry(new MenuEntry("Item Delimiters", DEFAULT_ENTRY)),
        m_high_data_rate_entry(new MenuEntry("High Data Rate", DEFAULT_ENTRY)),
        m_invisibility_entry(new MenuEntry("Invisibility", DEFAULT_ENTRY, entries::network::invisibility_menu)),
        m_disable_idle_disconnect_entry(new MenuEntry("Disable Idle Disconnect", DEFAULT_ENTRY)),
        m_instant_disconnect_entry(new MenuEntry("Instant Disconnect", nullptr, entries::network::instant_disconnect_game)),
        m_event_frame_modifier_entry(new MenuEntry("Event Frame Modifier", DEFAULT_ENTRY, entries::network::event_frame_modifier_menu)),
        m_friend_info_modifier_entry(new MenuEntry("Friend Info Modifier", DEFAULT_ENTRY, entries::network::friend_info_modifier_menu)),
        m_mii_matching_viewer_entry(new MenuEntry("Mii Matching Viewer", DEFAULT_ENTRY)),
        m_force_replacement_entry(new MenuEntry("Force Replacement", DEFAULT_ENTRY, entries::network::force_replacement_menu)),
        m_protections_entry(new MenuEntry("Protections", DEFAULT_ENTRY, entries::network::protections_menu)),
         
        m_rainbow_entry(new MenuEntry("Rainbow", entries::base::rainbow_game, entries::base::rainbow_menu))
    {
        m_plugin_menu->SynchronizeWithFrame(true);
        m_plugin_menu->ShowWelcomeMessage(false);
        m_plugin_menu->OnNewFrame = [](Time)
        {
            auto &settings = FwkSettings::Get();

            if (g_menu->m_rainbow_entry->IsActivated())
            {
                g_rainbow_service->run();
                auto const color = g_rainbow_service->get_ctrpf_color();

                g_menu->m_plugin_menu->Title() = color << NAME;
                settings.MenuSelectedItemColor = color;
            }
            else
            {
                g_menu->m_plugin_menu->Title() = NAME;
                settings.SetThemeDefault();
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
        if (auto item = new MenuFolder("Item"))
        {
            *item += m_item_wheel_entry;
            *item += m_item_rapidfire_entry;
            *item += m_item_usage_entry;
            *item += m_item_drop_entry;
            *item += m_item_hang_entry;
            *item += m_item_rain_entry;
            *item += m_item_limiters_entry;
            *item += m_zero_gravity_shells_entry;
            *item += m_rainbow_shell_stripes_entry;
            *item += m_blue_shell_battle_crash_fix_entry;

            *m_plugin_menu += item;
        }

        if (auto kart = new MenuFolder("Kart"))
        {
            *kart += m_invincibility_entry;
            *kart += m_intangibility_entry;
            *kart += m_kart_statuses_entry;
            *kart += m_killer_control_entry;
            *kart += m_instant_respawn_entry;
            *kart += m_instant_miniturbo_entry;

            *m_plugin_menu += kart;
        }

        if (auto mode = new MenuFolder("Mode"))
        {
            *mode += m_drive_during_sync_entry;
            *mode += m_trigger_respawn_entry;

            *m_plugin_menu += mode;
        }

        if (auto network = new MenuFolder("Network"))
        {
            *network += m_kart_warp_entry;
            *network += m_item_delimiters_entry;
            *network += m_high_data_rate_entry;
            *network += m_invisibility_entry;
            *network += m_disable_idle_disconnect_entry;
            *network += m_instant_disconnect_entry;
            *network += m_event_frame_modifier_entry;
            *network += m_friend_info_modifier_entry;
            *network += m_mii_matching_viewer_entry;
            *network += m_force_replacement_entry;
            *network += m_protections_entry;

            *m_plugin_menu += network;
        }
        
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
        // Item
        *GetArg<menu_types::item_rain_data_t>(m_item_rain_entry) = {};
        *GetArg<menu_types::item_rapidfire_data_t>(m_item_rapidfire_entry) = {};
        *GetArg<menu_types::item_wheel_data_t>(m_item_wheel_entry) = {SIZE_MAX};
        
        // Base
        m_rainbow_entry->Enable();
    }
}