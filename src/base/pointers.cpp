#include <base/pointers.hpp>

#include <base/memory/all.hpp>

namespace base
{
	pointers::pointers()
	{
		auto batch = memory::batch();
		
		batch.run(memory::ranges::c_text);

		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}
