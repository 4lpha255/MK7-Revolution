#include <base/entries.hpp>

#include <base/services/rainbow_service.hpp>

namespace base
{
    void entries::base::rainbow::game(CTRPluginFramework::MenuEntry *)
    {
        g_rainbow_service->run();
    }
}