#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

namespace base
{
    void entries::base::enabled_features_menu(CTRPluginFramework::MenuEntry *)
    {
        auto keyboard = CTRPluginFramework::Keyboard("Features");

        auto &enabled_features = g_settings.m_options.base.enabled_features;

        while (true)
        {
            auto entries = g_menu->get_feature_entries();
            if (!enabled_features.show_all)
                std::erase_if(entries, [](auto const &e) { return !e->IsActivated(); });
            std::sort(entries.begin(), entries.end(), [](auto const &lhs, auto const &rhs) { return lhs->Name() < rhs->Name(); });

            auto options = std::vector<std::string>{ std::format("[Show all] ({})", menu::toggle_name(enabled_features.show_all)) };
            std::for_each(entries.begin(), entries.end(), [&](auto const &e) { options.push_back(std::format("{} ({})", e->Name(), menu::toggle_name(e->IsActivated()))); });
            keyboard.Populate(options);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: enabled_features.show_all ^= true; break;
                default:
                {
                    auto const &e = entries.at(choice - 1);
                    if (e->IsActivated())
                        e->Disable();
                    else
                        e->Enable();
                    break;
                }
            }
        }
    }
}