#include <base/services/message_service.hpp>

#include <base/pointers.hpp>

#include <base/sead/safe_string.hpp>

namespace base
{
    message_service::message_service()
    :
        m_converter()
    {
        g_message_service = this;
    }

    message_service::~message_service()
    {
        g_message_service = nullptr;
    }

    std::string message_service::get(char const *category, LMS_MessageID message_id)
    {
        auto result_buffer = static_cast<char16_t *>(nullptr);
        auto const category_string = _sead::safe_string(category);

        auto const message_data = g_pointers->m_UI_MessageIDConverter_getMessageData(nullptr, &category_string);
        g_pointers->m_UI_MessageData_getMessage(&result_buffer, message_data, message_id);

        return m_converter.to_bytes(result_buffer);
    }
}