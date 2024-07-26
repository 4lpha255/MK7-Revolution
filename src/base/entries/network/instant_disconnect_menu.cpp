#include <base/entries.hpp>

#include <base/pointers.hpp>

#include <Net/NetworkEngine.hpp>
#include <Net/NetworkErrorHandler.hpp>

namespace base
{
    void entries::network::instant_disconnect_game(CTRPluginFramework::MenuEntry *entry)
    {
        (*g_pointers->m_network_engine)->m_network_error_handler->m_error_code = 0xB;
    }
}