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

        inline auto get(u32 id) { return get(static_cast<LMS_MessageID>(id)); };
        
        std::string get(LMS_MessageID);
        std::string get(char const *, LMS_MessageID);

    private:
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> m_converter;
    };

    inline message_service *g_message_service{};
}