#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <magic_enum/magic_enum_all.hpp>

#include <format>

namespace base
{
    void entries::kart::kart_effect_color_modifier_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
		keyboard.DisplayTopScreen = true;

        auto &kart_effect_color_modifier = g_settings.m_options.kart.kart_effect_color_modifier;

        while (true)
        {
            keyboard.GetMessage() = entry->Name();
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Star ({}, {})", menu::toggle_name(kart_effect_color_modifier.star.enabled), magic_enum::enum_name(kart_effect_color_modifier.star.mode)),
            });

			auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0:
                {
                    while (true)
                    {
                        keyboard.GetMessage() = entry->Name() + "\nStar";
                        auto options = std::vector<std::string>
                        {
                            std::format("Enabled ({})", menu::toggle_name(kart_effect_color_modifier.star.enabled)),
                            std::format("Mode ({})", magic_enum::enum_name(kart_effect_color_modifier.star.mode))
                        };
                        if (kart_effect_color_modifier.star.mode == decltype(kart_effect_color_modifier.star.mode)::Custom)
                            options.push_back(CTRPluginFramework::Color(kart_effect_color_modifier.star.color.as_u32()) << "Color");
                        keyboard.Populate(options);

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: kart_effect_color_modifier.star.enabled ^= true; break;
                            case 1: kart_effect_color_modifier.star.mode = magic_enum::enum_next_value_circular(kart_effect_color_modifier.star.mode); break;
                            case 2:
                            {
                                keyboard.GetMessage() = entry->Name() + "\nStar\nColor";

                                while (true)
                                {
                                    keyboard.Populate(std::vector<std::string>
                                    {
                                        CTRPluginFramework::Color(kart_effect_color_modifier.star.color.r.as_u8(), 0, 0) << "Red",
                                        CTRPluginFramework::Color(0, kart_effect_color_modifier.star.color.g.as_u8(), 0) << "Green",
                                        CTRPluginFramework::Color(0, 0, kart_effect_color_modifier.star.color.b.as_u8()) << "Blue",
                                    });

                                    auto const choice = keyboard.Open();
                                    if (choice < 0)
                                        break;

                                    switch (choice)
                                    {
                                        case 0: keyboard.Open(kart_effect_color_modifier.star.color.r.v, kart_effect_color_modifier.star.color.r.v); break;
                                        case 1: keyboard.Open(kart_effect_color_modifier.star.color.g.v, kart_effect_color_modifier.star.color.g.v); break;
                                        case 2: keyboard.Open(kart_effect_color_modifier.star.color.b.v, kart_effect_color_modifier.star.color.b.v); break;
                                    }
                                }

                                break;
                            }
                        }
                    }

                    break;
                }
            }
        }
    }
}