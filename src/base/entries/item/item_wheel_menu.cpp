#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <base/services/message_service.hpp>

#include <magic_enum/magic_enum_all.hpp>

#include <format>

namespace base
{
    void entries::item::item_wheel_menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
		keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(false);

        auto const items = std::to_array({ Item::eItemSlot::Banana, Item::eItemSlot::KouraG, Item::eItemSlot::KouraR, Item::eItemSlot::Kinoko, Item::eItemSlot::Bomhei, Item::eItemSlot::Gesso, Item::eItemSlot::KouraB, Item::eItemSlot::Kinoko3, Item::eItemSlot::Star, Item::eItemSlot::Killer, Item::eItemSlot::Thunder, Item::eItemSlot::KinokoP, Item::eItemSlot::Flower, Item::eItemSlot::Tail, Item::eItemSlot::Seven, Item::eItemSlot::Test3, Item::eItemSlot::Test4, Item::eItemSlot::Banana3, Item::eItemSlot::KouraG3, Item::eItemSlot::KouraR3, Item::eItemSlot::Empty });

		auto &item_wheel = g_settings.m_options.item.item_wheel;

        while (true)
        {
            keyboard.GetMessage() = entry->Name();
            keyboard.Populate(std::vector<std::string>
            {
                std::format("{} ({})", g_message_service->get(LMS_MessageID::Items), item_wheel.items.size()),
                std::format("Cycler ({}, {})", menu::toggle_name(item_wheel.cycler.enabled), item_wheel.cycler.delay),
                std::format("Decide Sound ({})", magic_enum::enum_name(item_wheel.decide_sound)),
                std::format("Decide Anim ({})", magic_enum::enum_name(item_wheel.decide_anim)),
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0:
                {
                    keyboard.GetMessage() = entry->Name() + "\n" + g_message_service->get(LMS_MessageID::Items);

                    while (true)
                    {
                        auto const all = item_wheel.items.size() == items.size();

                        auto options = std::vector<std::string>{ std::format("[All] ({})", menu::toggle_name(all)) };
                        std::for_each(items.begin(), items.end(), [&](auto const &i) { options.push_back(std::format("{} ({})", utils::item_name(i), menu::toggle_name(item_wheel.items.contains(i)))); });
                        keyboard.Populate(options);

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0:
                            {
                                if (all)
                                    item_wheel.items.clear();
                                else
                                    std::for_each(items.begin(), items.end(), [&](auto const &i) { item_wheel.items.emplace(i); });
                                break;
                            }
                            default:
                            {
                                if (auto const item = items.at(choice - 1); item_wheel.items.contains(item))
                                    item_wheel.items.erase(item);
                                else
                                    item_wheel.items.emplace(item);
                                break;
                            }
                        }
                    }

                    break;
                }
                case 1:
                {
                    keyboard.GetMessage() = entry->Name() + "\nCycler";

                    while (true)
                    {
                        keyboard.Populate(std::vector<std::string>
                        {
                            std::format("Enabled ({})", menu::toggle_name(item_wheel.cycler.enabled)),
                            std::format("Delay ({})", item_wheel.cycler.delay)
                        });

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        switch (choice)
                        {
                            case 0: item_wheel.cycler.enabled ^= true; break;
                            case 1: keyboard.Open(item_wheel.cycler.delay, item_wheel.cycler.delay); break;
                        }
                    }

                    break;
                }
                case 2: item_wheel.decide_sound = magic_enum::enum_next_value_circular(item_wheel.decide_sound); break;
                case 3: item_wheel.decide_anim = magic_enum::enum_next_value_circular(item_wheel.decide_anim); break;
            }
        }
    }
}