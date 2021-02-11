#pragma once

#include <krayte/kr8md/pak.h>

namespace kr8md
{
#if defined(__AVX2__)
    KR8MD_INLINE pfloat_8 load(float const *const addr)
    {
        return _mm256_loadu_ps(addr);
    }
#elif defined(__SSE4_2__)
    KR8MD_INLINE pfloat4 load(float const *const addr)
    {
        return _mm_loadu_ps(addr);
    }
#endif

#if defined(__AVX2__)
    KR8MD_INLINE pfloat_8 load_aligned(float const *const addr)
    {
        return _mm256_load_ps(addr);
    }
#elif defined(__SSE4_2__)
    KR8MD_INLINE pfloat4 load_aligned(float const *const addr)
    {
        return _mm_load_ps(addr);
    }
#endif

#if defined(__AVX2__)
    KR8MD_INLINE pfloat_8 load_unaligned(float const *const addr)
    {
        return _mm256_loadu_ps(addr);
    }
#elif defined(__SSE4_2__)
    KR8MD_INLINE pfloat4 load_unaligned(float const *const addr)
    {
        return _mm_loadu_ps(addr);
    }
#endif
} // namespace kr8md