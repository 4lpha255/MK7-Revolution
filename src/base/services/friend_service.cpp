#include <base/services/friend_service.hpp>

extern "C"
{
#include <3ds/services/frd.h>
#include <3ds/result.h>
}

#include <base/notifier.hpp>
#include <base/settings.hpp>
#include <base/utils.hpp>

#include <cstdlib> // abort
#include <map>

#define AMOUNT 1

namespace base
{
    friend_service::friend_service()
    :
        m_delay{}
    {
        if (R_FAILED(frdInit(false)))
            abort();

        g_friend_service = this;
    }

    friend_service::~friend_service()
    {
        g_friend_service = nullptr;

        frdExit();
    }

    void friend_service::run()
    {
        static auto const messages = std::map<FriendNotificationTypes, std::string_view>
        {
            { USER_WENT_ONLINE, "You went online!" },
            { USER_WENT_OFFLINE, "You went offline!" },
            { FRIEND_WENT_ONLINE, "{} went online." },
            { FRIEND_UPDATED_PRESENCE, "{} updated their presence." },
            { FRIEND_UPDATED_MII, "{} updated their Mii." },
            { FRIEND_UPDATED_PROFILE, "{} updated their profile." },
            { FRIEND_WENT_OFFLINE, "{} went offline." },
            { FRIEND_REGISTERED_USER, "{} registered you as a friend." },
            { FRIEND_SENT_JOINABLE_INVITATION, "{} sent you an invitation." },
        };

        auto const &friends = g_settings.m_options.base.friends;

        if (++m_delay <= friends.delay)
            return;

        m_delay = {};

        while (true)
        {
            auto event = NotificationEvent{};
            auto count = u32{};
            if (R_FAILED(FRD_GetEventNotification(&event, AMOUNT, &count)) || count != AMOUNT)
                return;

            auto const type = static_cast<FriendNotificationTypes>(event.type);
            auto const it = messages.find(type);
            if (it == messages.end() || !friends.events.contains(type))
                return;

            auto mii = FriendMii{};
            if (R_FAILED(FRD_GetFriendMii(&mii, &event.sender, AMOUNT)))
                return;

            g_notifier.vsend(it->second, utils::mii_name(mii.mii));
        }
    }
}