#pragma once

#include <format>

namespace base
{
    class notifier
    {
    public:
        template <typename ...args_t>
		void send(std::format_string<args_t ...>, args_t &&...);

        template <typename ...args_t>
		void vsend(std::string_view, args_t &&...);

    private:
        void notify(std::string);
    };

    template <typename ...args_t>
    inline void notifier::send(std::format_string<args_t ...> fmt, args_t &&...args)
    {
        auto str = std::format(fmt, std::forward<args_t>(args)...);
        notify(str);
    }

    template <typename ...args_t>
    inline void notifier::vsend(std::string_view fmt, args_t &&...args)
    {
        auto str = std::vformat(fmt, std::make_format_args(std::forward<args_t const>(args)...));
        notify(str);
    }

    inline notifier g_notifier;
}