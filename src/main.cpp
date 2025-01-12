#include <3ds.h>

#include <base/notifier.hpp>
#include <base/files.hpp>
#include <base/logger.hpp>
#include <base/settings.hpp>
#include <base/menu.hpp>
#include <base/patches.hpp>
#include <base/pointers.hpp>
#include <base/hooking.hpp>

#include <base/services/message_service.hpp>
#include <base/services/rainbow_service.hpp>

namespace CTRPluginFramework
{
    using namespace base;

    int main()
    {
        g_notifier.send(NAME "!");

        auto files_instance = std::make_unique<files>();
        g_logger.info("Greetings from " NAME "!");

        g_settings.load();
        g_logger.info("Settings loaded.");

        auto menu_instance = std::make_unique<menu>();
        g_logger.info("Menu created.");

        auto pointers_instance = std::make_unique<pointers>();
        g_logger.info("Pointers initialized.");

        auto hooking_instance = std::make_unique<hooking>();
        g_logger.info("Hooking initialized.");

        auto patches_instance = std::make_unique<patches>();
        g_logger.info("Patches initialized.");

        auto message_service_instance = std::make_unique<message_service>();
        auto rainbow_service_instance = std::make_unique<rainbow_service>();
        g_logger.info("Services initialized.");

        g_hooking->enable();
        g_logger.info("Hooking enabled.");

        g_notifier.send("Enjoy. :)");
        g_menu->run();

        g_hooking->disable();
        g_logger.info("Hooking disabled.");

        rainbow_service_instance.reset();
        message_service_instance.reset();
        g_logger.info("Services uninitialized.");

        patches_instance.reset();
        g_logger.info("Patches uninitialized.");

        hooking_instance.reset();
        g_logger.info("Hooking uninitialized.");

        pointers_instance.reset();
        g_logger.info("Pointers uninitialized.");

        menu_instance.reset();
        g_logger.info("Menu deleted.");

        g_settings.store();
        g_logger.info("Settings stored.");

        g_logger.info("Farewell!");
        files_instance.reset();

        return EXIT_SUCCESS;
    }

    void PatchProcess(FwkSettings &settings)
    {
        settings.ThreadPriority = 0x3E;
        settings.WaitTimeToBoot = Time::Zero;
#ifdef _DEBUG
        settings.CachedDrawMode = true;
#endif

        files::set_working_directory();
    }

    void UseGameStackToInit() {}
}
