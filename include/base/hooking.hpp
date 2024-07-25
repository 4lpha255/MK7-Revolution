#pragma once

#include "hook_types/all.hpp"

#include "hooks.hpp"

namespace base
{
    class hooking
    {
	public:
		explicit hooking();
		~hooking();

        inline bool is_enabled() const { return m_enabled; }

        void enable();
		void disable();

    private:
        friend hooks;

        bool m_enabled{};
    };

    inline hooking *g_hooking{};
}