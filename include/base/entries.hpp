#pragma once

#include <CTRPluginFramework.hpp>

namespace base
{
	struct entries
	{
		struct item
		{
			static void disable_item_clear_menu(CTRPluginFramework::MenuEntry *);
			static void item_drop_menu(CTRPluginFramework::MenuEntry *);
			static void item_hang_menu(CTRPluginFramework::MenuEntry *);
			static void item_limiters_menu(CTRPluginFramework::MenuEntry *);
			static void item_rain_menu(CTRPluginFramework::MenuEntry *);
			static void item_rapidfire_menu(CTRPluginFramework::MenuEntry *);
			static void item_selfstrike_menu(CTRPluginFramework::MenuEntry *);
			static void item_terrain_menu(CTRPluginFramework::MenuEntry *);
			static void item_usage_menu(CTRPluginFramework::MenuEntry *);
			static void item_wheel_menu(CTRPluginFramework::MenuEntry *);
			static void zero_gravity_shells_menu(CTRPluginFramework::MenuEntry *);
		};

		struct kart
		{
			static void future_fly_menu(CTRPluginFramework::MenuEntry *);
			static void intangibility_menu(CTRPluginFramework::MenuEntry *);
			static void instant_acceleration_menu(CTRPluginFramework::MenuEntry *);
			static void instant_miniturbo_menu(CTRPluginFramework::MenuEntry *);
			static void kart_effect_color_modifier_menu(CTRPluginFramework::MenuEntry *);
			static void kart_statuses_menu(CTRPluginFramework::MenuEntry *);
			static void kart_usage_menu(CTRPluginFramework::MenuEntry *);
			static void killer_control_menu(CTRPluginFramework::MenuEntry *);
		};

		struct network
		{
			static void event_frame_modifier_menu(CTRPluginFramework::MenuEntry *);
			static void force_replacement_menu(CTRPluginFramework::MenuEntry *);
			static void friend_info_modifier_menu(CTRPluginFramework::MenuEntry *);
			static void goal_score_modifier_menu(CTRPluginFramework::MenuEntry *);
			static void instant_disconnect_game(CTRPluginFramework::MenuEntry *);
			static void invisibility_menu(CTRPluginFramework::MenuEntry *);
			static void item_delimiters_menu(CTRPluginFramework::MenuEntry *);
			static void protections_menu(CTRPluginFramework::MenuEntry *);
			static void vr_extender_fix_game(CTRPluginFramework::MenuEntry *);
		};

		struct system
		{
			static void save_data_modifier_game(CTRPluginFramework::MenuEntry *);
		};

#ifdef _DEBUG
		struct debug
		{
			static void toggle_hooks_menu(CTRPluginFramework::MenuEntry *);
		};
#endif

		struct base
		{
			static void rainbow_game(CTRPluginFramework::MenuEntry *);
			static void rainbow_menu(CTRPluginFramework::MenuEntry *);
		};
	};
}