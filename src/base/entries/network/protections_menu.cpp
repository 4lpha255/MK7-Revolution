#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <format>

namespace base
{
    void entries::network::protections_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
        keyboard.DisplayTopScreen = true;

        auto &protections = g_settings.m_options.network.protections;

        while (true)
        {
            auto const categories = std::vector<std::string>{ "Item", "Kart", "Network" };

            keyboard.GetMessage() = entry->Name();
            keyboard.Populate(categories);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            keyboard.GetMessage() = std::format("{}\n{}", entry->Name(), categories.at(choice));

            switch (choice)
            {
                // Item
                case 0:
                {
                    while (true)
                    {
                        keyboard.Populate(std::vector<std::string>
                        {
                            std::format("Killer Items ({})", menu::toggle_name(protections.item.killer_items)),
                            std::format("Tail Items ({})", menu::toggle_name(protections.item.tail_items))
                        });

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: protections.item.killer_items ^= true; break;
                            case 1: protections.item.tail_items ^= true; break;
                        }
                    }
                    
                    break;
                }

                // Kart
                case 1:
                {
                    while (true)
                    {
                        keyboard.Populate(std::vector<std::string>
                        {
                            std::format("Accident Type ({})", menu::toggle_name(protections.kart.accident_type))
                        });

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: protections.kart.accident_type ^= true; break;
                        }
                    }

                    break;
                }

                // Net
                case 2:
                {
                    while (true)
                    {
                        keyboard.Populate(std::vector<std::string>
                        {
                            std::format("System Info ({})", menu::toggle_name(protections.network.system_info))
                        });

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: protections.network.system_info ^= true; break;
                        }
                    }

                    break;
                }
            }
        }
    }
}