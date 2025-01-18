#pragma once

#include <3ds/services/frd.h>

#include <types.h>

#include <set>

namespace base
{
	class settings
	{
	public:
		bool load();
		bool store();
		bool reset();

		struct options
		{
			struct base
			{
				struct enabled_features
				{
					bool show_all{ false };
				}
				enabled_features;

				struct friends
				{
					u32 delay{ 60 };
					std::set<NotificationTypes> events
					{
						FRIEND_WENT_ONLINE,
						FRIEND_UPDATED_MII,
						FRIEND_UPDATED_PROFILE,
						FRIEND_WENT_OFFLINE,
					};
				}
				friends;
				
				struct rainbow
				{
					float hue_amount{ 1.f / 300.f };
					float saturation{ 1.f };
					float value{ 1.f };
				}
				rainbow;
			}
			base;
		}
		m_options{};

	private:
		bool load_impl();
	};

	inline settings g_settings;
}
