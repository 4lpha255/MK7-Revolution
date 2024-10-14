#pragma once

#include <CTRPluginFramework.hpp>

namespace base
{
	struct entries
	{
#ifdef _DEBUG
		struct debug
		{
			static void toggle_hooks_menu(CTRPluginFramework::MenuEntry *);
		};
#endif

		struct base
		{
			static void disable_features(CTRPluginFramework::MenuEntry *);
			static void rainbow_game(CTRPluginFramework::MenuEntry *);
			static void rainbow_menu(CTRPluginFramework::MenuEntry *);
		};
	};
}