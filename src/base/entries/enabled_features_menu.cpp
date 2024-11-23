#include <base/entries.hpp>

#include <base/menu.hpp>

namespace base
{
    void entries::enabled_features_menu(CTRPluginFramework::MenuEntry *)
    {
        auto keyboard = CTRPluginFramework::Keyboard("Features");

        while (true)
        {
            auto const entries = g_menu->get_feature_entries();

            auto options = std::vector<std::string>();
            std::transform(entries.begin(), entries.end(), std::back_inserter(options), [](auto const &e) { return std::format("{} ({})", e->Name(), menu::toggle_name(e->IsActivated())); });
            keyboard.Populate(options);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            auto const &e = entries.at(choice);
            if (e->IsActivated())
                e->Disable();
            else
                e->Enable();
        }
    }
}