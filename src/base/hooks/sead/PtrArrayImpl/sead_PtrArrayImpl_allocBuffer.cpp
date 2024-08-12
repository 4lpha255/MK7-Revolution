#include <base/hooking.hpp>
#include <base/features.hpp>
#include <base/pointers.hpp>

namespace base
{
    void hooks::sead_PtrArrayImpl_allocBuffer(sead::PtrArrayImpl *_this, s32 max, sead::Heap *heap, s32 align)
    {
        // Make sure allocBuffer is being called inside the stripe constructor
        if (__builtin_return_address(0) == g_pointers->m_Effect_GPUPtclStripe_GPUPtclStripe_0x2D0)
        {
            features::item::item_limiters::stripes(max);
        }

        g_hooking->m_sead_PtrArrayImpl_allocBuffer_hook.call_original<void>(_this, max, heap, align);
    }
}