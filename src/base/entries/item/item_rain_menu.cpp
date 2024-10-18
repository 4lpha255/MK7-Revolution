#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <format>

namespace base
{
	void entries::item::item_rain_menu(CTRPluginFramework::MenuEntry *entry)
	{
		auto keyboard = CTRPluginFramework::Keyboard();
		keyboard.DisplayTopScreen = true;
		keyboard.IsHexadecimal(false);

		auto const items = std::to_array({ Item::eItemType::KouraG, Item::eItemType::KouraR, Item::eItemType::Banana, Item::eItemType::Kinoko, Item::eItemType::Star, Item::eItemType::KouraB, Item::eItemType::Bomhei, Item::eItemType::Gesso, Item::eItemType::Flower });

		auto &item_rain = g_settings.m_options.item.item_rain;

		while (true)
		{
			keyboard.GetMessage() = entry->Name();
			keyboard.Populate(std::vector<std::string>
			{
				std::format("Items ({})", item_rain.items.size()),
				std::format("Owned ({})", menu::s_toggles[item_rain.owned]),
				std::format("Multi ({})", menu::s_toggles[item_rain.multi]),
				std::format("Self ({})", menu::s_toggles[item_rain.self]),
				std::format("Speed ({}, {})", menu::s_toggles[item_rain.speed.enabled], item_rain.speed.value),
                std::format("Delay ({})", item_rain.delay),
				std::format("Shape ({})", magic_enum::enum_name(item_rain.shape)),
				std::format("Height ({})", item_rain.height),
				std::format("Width ({})", item_rain.width)
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
						keyboard.GetMessage() = entry->Name() + "\nItems";
						auto options = std::vector<std::string>();
						std::for_each(items.begin(), items.end(), [&](auto const &i) { options.push_back(std::format("{} ({})", magic_enum::enum_name(i), menu::s_toggles[item_rain.items.contains(i)])); });
						keyboard.Populate(options);

						auto const choice = keyboard.Open();
						if (choice < 0)
							break;

						auto const item = items.at(choice);

						if (item_rain.items.contains(item))
							item_rain.items.erase(item);
						else
							item_rain.items.emplace(item);
					}

					break;
				}
				case 1: item_rain.owned ^= true; break;
				case 2: item_rain.multi ^= true; break;
				case 3: item_rain.self ^= true; break;
				case 4:
				{
					while (true)
					{
						keyboard.Populate(std::vector<std::string>
						{
							std::format("Status ({})", menu::s_toggles[item_rain.speed.enabled]),
							std::format("Value ({})", item_rain.speed.value)
						});

						auto const choice = keyboard.Open();
						if (choice < 0)
							break;

						switch (choice)
						{
							case 0: item_rain.speed.enabled ^= true; break;
							case 1: keyboard.Open(item_rain.speed.value, item_rain.speed.value); break;
						}
					}

					break;
				}
                case 5: keyboard.Open(item_rain.delay, item_rain.delay); break;
				case 6: utils::enum_next(item_rain.shape); break;
			    case 7: keyboard.Open(item_rain.height, item_rain.height); break;
				case 8: keyboard.Open(item_rain.width, item_rain.width); break;
			}
		}
	}
}