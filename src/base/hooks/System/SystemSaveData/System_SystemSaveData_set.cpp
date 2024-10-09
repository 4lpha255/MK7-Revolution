#include <base/hooking.hpp>
#include <base/pointers.hpp>

namespace base
{
    bool hooks::System_SystemSaveData_set(System::SystemSaveData *_this, System::SystemSaveData *src)
    {
        // Late-initialized because it shifts by 8 bytes between 1.0 and 1.1+ inside SaveDataManager; though the offset issue persists if that class is ever needed.
        g_pointers->m_system_save_data = _this;

        return g_hooking->m_System_SystemSaveData_set_hook.call_original<bool>(_this, src);
    }
}