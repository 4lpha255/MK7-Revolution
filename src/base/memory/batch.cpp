#include <base/memory/batch.hpp>

#include <base/logger.hpp>

namespace base::memory
{
	void batch::add(std::string_view name, memory::pattern pattern, std::function<void (memory::handle)> callback)
	{
		m_entries.emplace_back(std::move(name), std::move(pattern), std::move(callback));
	}

	void batch::run(range range)
	{
		auto task_args = std::vector<task_arg>();
		auto tasks = std::vector<CTRPluginFramework::Task>();

		task_args.reserve(m_entries.size());
		tasks.reserve(m_entries.size());

		std::for_each(m_entries.begin(), m_entries.end(), [&](auto const &e)
		{
			task_args.emplace_back(range, e);
			tasks.emplace_back(&task_func, &task_args.back());
		});
		
		std::for_each(tasks.begin(), tasks.end(), [](auto const &t) { t.Start(); });
		auto const failed = std::any_of(tasks.begin(), tasks.end(), [](auto const &t) { return t.Wait(); });

		m_entries.clear();

		if (failed)
			abort();
	}

	s32 batch::task_func(void *param)
	{
		auto const arg = static_cast<task_arg *>(param);

		if (auto handle = arg->m_range.scan(arg->m_entry.m_pattern))
		{
			if (arg->m_entry.m_callback)
				std::invoke(std::move(arg->m_entry.m_callback), handle);

			g_logger.debug("Batch entry '{}' ({}) found.", arg->m_entry.m_name, handle.as<void *>());
			return EXIT_SUCCESS;
		}

		g_logger.info("Failed to find batch entry '{}'.", arg->m_entry.m_name);
		return EXIT_FAILURE;
	}
}