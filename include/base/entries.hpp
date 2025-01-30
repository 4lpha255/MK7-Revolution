#pragma once

#include <ctrpf.hpp>

namespace base
{
	struct entries
	{
		struct item
		{
			struct shell_stripe_color_modifier
			{
				static void game(CTRPluginFramework::MenuEntry *);
				static void menu(CTRPluginFramework::MenuEntry *);
			};

			static void disable_item_clear_menu(CTRPluginFramework::MenuEntry *);
			static void item_drop_menu(CTRPluginFramework::MenuEntry *);
			static void item_fixes_menu(CTRPluginFramework::MenuEntry *);
			static void item_hang_menu(CTRPluginFramework::MenuEntry *);
			static void item_limiters_menu(CTRPluginFramework::MenuEntry *);
			static void item_model_menu(CTRPluginFramework::MenuEntry *);
			static void item_rain_menu(CTRPluginFramework::MenuEntry *);
			static void item_rapidfire_menu(CTRPluginFramework::MenuEntry *);
			static void item_selfstrike_menu(CTRPluginFramework::MenuEntry *);
			static void item_terrain_menu(CTRPluginFramework::MenuEntry *);
			static void item_usage_menu(CTRPluginFramework::MenuEntry *);
			static void item_wheel_menu(CTRPluginFramework::MenuEntry *);
			static void shell_gravity_modifier_menu(CTRPluginFramework::MenuEntry *);
		};

		struct kart
		{
			struct angry_wiggler
			{
				static void game(CTRPluginFramework::MenuEntry *);
				static void menu(CTRPluginFramework::MenuEntry *);
			};

			static void future_fly_menu(CTRPluginFramework::MenuEntry *);
			static void intangibility_menu(CTRPluginFramework::MenuEntry *);
			static void instant_acceleration_menu(CTRPluginFramework::MenuEntry *);
			static void instant_miniturbo_menu(CTRPluginFramework::MenuEntry *);
			static void kart_effect_color_modifier_menu(CTRPluginFramework::MenuEntry *);
			static void kart_statuses_menu(CTRPluginFramework::MenuEntry *);
			static void kart_usage_menu(CTRPluginFramework::MenuEntry *);
			static void kart_vulnerabilities_menu(CTRPluginFramework::MenuEntry *);
			static void killer_control_menu(CTRPluginFramework::MenuEntry *);
		};

		struct network
		{
			static void course_vote_controller_menu(CTRPluginFramework::MenuEntry *);
			static void event_frame_modifier_menu(CTRPluginFramework::MenuEntry *);
			static void force_replacement_menu(CTRPluginFramework::MenuEntry *);
			static void friend_info_modifier_menu(CTRPluginFramework::MenuEntry *);
			static void goal_score_modifier_menu(CTRPluginFramework::MenuEntry *);
			static void instant_disconnect_game(CTRPluginFramework::MenuEntry *);
			static void invisibility_menu(CTRPluginFramework::MenuEntry *);
			static void item_delimiters_menu(CTRPluginFramework::MenuEntry *);
			static void mii_dumper_menu(CTRPluginFramework::MenuEntry *);
			static void protections_menu(CTRPluginFramework::MenuEntry *);
			static void vr_extender_fix_game(CTRPluginFramework::MenuEntry *);
		};

		struct system
		{
			static void save_data_modifier_game(CTRPluginFramework::MenuEntry *);
		};

		struct ui
		{
			struct enhanced_minimap
			{
				static void game(CTRPluginFramework::MenuEntry *);
				static void menu(CTRPluginFramework::MenuEntry *);
			};

			struct mii_heads
			{
				static void game(CTRPluginFramework::MenuEntry *);
				static void menu(CTRPluginFramework::MenuEntry *);
			};

			static void grand_prix_timer_menu(CTRPluginFramework::MenuEntry *);
		};

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