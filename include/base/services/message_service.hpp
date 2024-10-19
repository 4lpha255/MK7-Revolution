#pragma once

#include <LMS_MessageID.hpp>

#include <codecvt>
#include <locale>

namespace base
{
    class message_service
    {
    public:
        explicit message_service();
        ~message_service();

        std::string get(char const *, LMS_MessageID);

    private:
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> m_converter;
    };

    inline message_service *g_message_service{};
}