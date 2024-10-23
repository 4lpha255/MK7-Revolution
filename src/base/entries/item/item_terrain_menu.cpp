#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <base/services/message_service.hpp>

#include <format>

namespace base
{
    void entries::item::item_terrain_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
		keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(false);

        auto const items = std::to_array({ Item::eItemType::KouraG, Item::eItemType::KouraR, Item::eItemType::Banana, Item::eItemType::Kinoko, Item::eItemType::Star, Item::eItemType::KouraB, Item::eItemType::Bomhei, Item::eItemType::Gesso, Item::eItemType::Flower });

        auto &item_terrain = g_settings.m_options.item.item_terrain;

        while (true)
        {
            keyboard.GetMessage() = entry->Name();
            keyboard.Populate(std::vector<std::string>
            {
                std::format("{} ({})", g_message_service->get("Menu", LMS_MessageID::Items), item_terrain.items.size()),
                std::format("Delay ({})", item_terrain.delay),
                std::format("Mode ({})", magic_enum::enum_name(item_terrain.mode))
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
                        keyboard.GetMessage() = entry->Name() + "\n" + g_message_service->get("Menu", LMS_MessageID::Items);
						auto options = std::vector<std::string>();
						std::for_each(items.begin(), items.end(), [&](auto const &i) { options.push_back(std::format("{} ({})", utils::item_name(i).value_or(std::string(magic_enum::enum_name(i))), menu::s_toggles[item_terrain.items.contains(i)])); });
						keyboard.Populate(options);

						auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

						auto const item = items.at(choice);

						if (item_terrain.items.contains(item))
							item_terrain.items.erase(item);
						else
							item_terrain.items.emplace(item);
					}

                    break;
                }
                case 1: keyboard.Open(item_terrain.delay, item_terrain.delay); break;
                case 2: utils::enum_next(item_terrain.mode); break;
            }
        }
    }
}