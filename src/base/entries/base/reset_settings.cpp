#include <base/entries.hpp>

#include <base/settings.hpp>

namespace base
{
    void entries::base::reset_settings(CTRPluginFramework::MenuEntry *entry)
    {
        if (CTRPluginFramework::MessageBox(entry->Name(), "Continue?", CTRPluginFramework::DialogType::DialogYesNo)())
            g_settings.reset();
    }
}