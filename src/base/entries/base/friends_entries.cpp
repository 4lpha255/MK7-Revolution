#include <base/entries.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <base/services/friend_service.hpp>

#include <magic_enum/magic_enum_all.hpp>

#include <format>

namespace base
{
    void entries::base::friends::game(CTRPluginFramework::MenuEntry *)
    {
        g_friend_service->run();
    }

    void entries::base::friends::menu(CTRPluginFramework::MenuEntry *entry)
    {
        auto keyboard = CTRPluginFramework::Keyboard();
        keyboard.DisplayTopScreen = true;
        keyboard.IsHexadecimal(false);

        auto &friends = g_settings.m_options.base.friends;

        while (true)
        {
            keyboard.GetMessage() = entry->Name();
            keyboard.Populate(std::vector<std::string>
            {
                std::format("Delay ({})", friends.delay),
                std::format("Events ({})", friends.events.size()),
            });

            auto const choice = keyboard.Open();
            if (choice < 0)
                break;

            switch (choice)
            {
                case 0: keyboard.Open(friends.delay, friends.delay); break;
                case 1:
                {
                    keyboard.GetMessage() = entry->Name() + "\nEvents";

                    while (true)
                    {
                        auto options = std::vector<std::string>();
                        magic_enum::enum_for_each<FriendNotificationTypes>([&](auto const e)
                        {
                            auto constexpr type = static_cast<FriendNotificationTypes>(e);
                            options.push_back(std::format("{} ({})", magic_enum::enum_name(type), menu::toggle_name(friends.events.contains(type))));
                        });
                        keyboard.Populate(options);

                        auto const choice = keyboard.Open();
                        if (choice < 0)
                            break;

                        auto const type = magic_enum::enum_value<FriendNotificationTypes>(choice);
                        if (friends.events.contains(type))
                            friends.events.erase(type);
                        else
                            friends.events.insert(type);
                    }
                    break;
                }
            }
        }        
    }
}