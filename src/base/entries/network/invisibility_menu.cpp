#include <base/entries.hpp>

#include <base/settings.hpp>
#include <base/utils.hpp>

#include <format>

namespace base
{
    void entries::network::invisibility_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
        keyboard.DisplayTopScreen = true;

        auto &invisibility = g_settings.m_options.network.invisibility;

        while (true)
        {
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Mode ({})", magic_enum::enum_name(invisibility.mode))
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: utils::enum_next(invisibility.mode); break;
            }
        }
    }
}