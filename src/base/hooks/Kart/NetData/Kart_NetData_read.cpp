#include <base/hooking.hpp>
#include <base/features.hpp>

namespace base
{
    bool hooks::Kart_NetData_read(Kart::NetData *_this, Net::NetworkBuffer *network_buffer, Kart::NetData **net_data_recv, Kart::NetData **net_data_target)
    {
        auto result = g_hooking->m_Kart_NetData_read_hook.call_original<bool>(_this, network_buffer, net_data_recv, net_data_target);

        if (result)
        {
            result = !features::network::protections::kart(*net_data_recv);
        }

        return result;
    }
}