#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <array>
#include <format>

namespace base
{
    void entries::item::item_limiters_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
        keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(false);

        auto const items = std::to_array({ Item::eItemType::KouraG, Item::eItemType::KouraR, Item::eItemType::Banana, Item::eItemType::Kinoko, Item::eItemType::Star, Item::eItemType::KouraB, Item::eItemType::Thunder, Item::eItemType::Bomhei, Item::eItemType::Gesso, Item::eItemType::Killer, Item::eItemType::Flower, Item::eItemType::Tail, Item::eItemType::Seven });

        auto &item_limiters = g_settings.m_options.item.item_limiters;

        while (true)
		{
            keyboard.GetMessage() = entry->Name();

            auto options = std::vector<std::string>();
            std::for_each(items.begin(), items.end(), [&](auto const &i)
            {
                auto const name = utils::item_name(i).value_or(std::string(magic_enum::enum_name(i)));
                if (item_limiters.items.contains(i))
                    options.push_back(std::format("{} ({}, {})", name, menu::toggle_name(item_limiters.items.at(i).enabled), item_limiters.items.at(i).amount));
                else
                    options.push_back(std::format("{}", name));
            });
            keyboard.Populate(options);

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            auto const &item = items.at(choice);
            item_limiters.items.try_emplace(item);

            while (true)
			{
                auto &e = item_limiters.items.at(item);

                keyboard.GetMessage() = std::format("{}\n{}", entry->Name(), magic_enum::enum_name(item));
                keyboard.Populate(std::vector<std::string>
                {
                    std::format("{}", menu::toggle_name(e.enabled)),
                    std::format("{}", e.amount)
                });

                auto const choice = keyboard.Open();
                if (choice < 0)
                    break;

                switch (choice)
                {
                    case 0: e.enabled ^= true; break;
                    case 1: keyboard.Open(e.amount, e.amount); break;
                }
            }
        }
    }
}