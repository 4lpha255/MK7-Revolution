#include <base/entries.hpp>

#include <base/pointers.hpp>

#include <Net/NetworkEngine.hpp>
#include <Net/NetworkErrorHandler.hpp>

namespace base
{
    void entries::network::instant_disconnect_game(CTRPluginFramework::MenuEntry *entry)
    {
        auto &code = (*g_pointers->m_network_engine)->m_network_error_handler->m_error_code;

        if (code == 0)
        {
            code = 0xB;
            CTRPluginFramework::MessageBox(entry->Name(), "Done.")();
        }
        else
        {
            code = 0;
            CTRPluginFramework::MessageBox(entry->Name(), "Reset.")();
        }
    }
}