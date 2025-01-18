#pragma once

#include <types.h>

namespace base
{
    class friend_service
    {
    public:
        explicit friend_service();
        ~friend_service();

        void run();

    private:
        u32 m_delay;
    };

    inline friend_service *g_friend_service{};
}