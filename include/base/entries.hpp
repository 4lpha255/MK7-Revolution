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
			struct friends
			{
				static void game(CTRPluginFramework::MenuEntry *);
				static void menu(CTRPluginFramework::MenuEntry *);
			};

			struct rainbow
			{
				static void game(CTRPluginFramework::MenuEntry *);
				static void menu(CTRPluginFramework::MenuEntry *);
			};

			static void disable_features_game(CTRPluginFramework::MenuEntry *);
			static void enabled_features_menu(CTRPluginFramework::MenuEntry *);
			static void reset_settings_game(CTRPluginFramework::MenuEntry *);
		};
	};
}