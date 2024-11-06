#pragma once

#include <ctrpf.hpp>

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
			static void disable_features_game(CTRPluginFramework::MenuEntry *);
			static void rainbow_game(CTRPluginFramework::MenuEntry *);
			static void rainbow_menu(CTRPluginFramework::MenuEntry *);
			static void reset_settings_game(CTRPluginFramework::MenuEntry *);
		};
	};
}