#include <base/entries.hpp>

#include <base/settings.hpp>
#include <base/utils.hpp>

#include <format>

namespace base
{
    void entries::item::item_rapidfire_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard(entry->Name());
		keyboard.DisplayTopScreen = true;
		keyboard.IsHexadecimal(false);

        auto &item_rapidfire = g_settings.m_options.item.item_rapidfire;

		while (true)
		{
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Mode ({})", magic_enum::enum_name(item_rapidfire.mode)),
                std::format("Delay ({})", item_rapidfire.delay),
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: utils::enum_next(item_rapidfire.mode); break;
                case 1: keyboard.Open(item_rapidfire.delay, item_rapidfire.delay); break;
            }
        }
    }
}