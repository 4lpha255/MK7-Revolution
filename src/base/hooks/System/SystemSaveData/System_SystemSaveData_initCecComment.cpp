#include <base/hooking.hpp>
#include <base/pointers.hpp>

namespace base
{
    void hooks::System_SystemSaveData_initCecComment(System::SystemSaveData *_this)
    {
        // Late-initialized because it shifts by 8 bytes between 1.0 and 1.1+ inside SaveDataManager; though the offset issue persists if that class is ever needed.
        g_pointers->m_system_save_data = _this;

        g_hooking->m_System_SystemSaveData_initCecComment_hook.call_original<void>(_this);
    }
}