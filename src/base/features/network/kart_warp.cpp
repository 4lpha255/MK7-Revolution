#include <base/features.hpp>

#include <base/menu.hpp>

#include <Kart/NetData.hpp>

namespace base
{
    void features::network::kart_warp(Kart::NetData *_this)
    {
        if (g_menu->m_kart_warp_entry->IsActivated())
            _this->m_kart_data.warp ^= true;
    }
}