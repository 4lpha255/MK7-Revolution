#include <base/features.hpp>

#include <base/menu.hpp>
#include <base/settings.hpp>

#include <Item/ItemObj/ItemObjKouraG.hpp>
#include <Kart/InfoProxy.hpp>

namespace base
{
    void features::item::shell_gravity_modifier(Item::ItemObjKouraG *_this)
    {
        if (g_menu->m_shell_gravity_modifier_entry->IsActivated() && !_this->m_info_proxy->isNetRecv())
        {
            auto const &shell_gravity_modifier = g_settings.m_options.item.shell_gravity_modifier;

            switch (shell_gravity_modifier.mode)
            {
            case decltype(shell_gravity_modifier.mode)::Custom:
                _this->m_gravity = shell_gravity_modifier.custom_value;
                break;
            case decltype(shell_gravity_modifier.mode)::Invert:
                _this->m_gravity = 1.f - _this->m_gravity;
                break;
            }

            if (shell_gravity_modifier.offset.enabled)
                _this->m_position.y += shell_gravity_modifier.offset.value;
        }
    }
}