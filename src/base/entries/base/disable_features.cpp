#include <base/entries.hpp>

#include <base/menu.hpp>

namespace base
{
    void entries::base::disable_features(CTRPluginFramework::MenuEntry *entry)
    {
        if (CTRPluginFramework::MessageBox(entry->Name(), "Continue?", CTRPluginFramework::DialogType::DialogYesNo)())
        {
            auto const entries = g_menu->get_feature_entries();
            std::for_each(entries.begin(), entries.end(), [](auto const &e) { e->Disable(); });
        }
    }
}