#pragma once

#include <krayte/kr8md/pak.h>
#include <krayte/kr8md/defaults.h>

namespace kr8md
{
#if defined(__AVX2__)
    KR8MD_INLINE void store(uint32_t *const addr, const puint32_8 &a)
    {
        _mm256_storeu_si256((__m256i *)addr, a);
    }

    KR8MD_INLINE void store(int32_t *const addr, const pint32_8 &a)
    {
        _mm256_storeu_si256((__m256i *)addr, a);
    }

    KR8MD_INLINE void store(float *const addr, const pfloat_8 a)
    {
        _mm256_storeu_ps(addr, a);
    }
#elif defined(__SSE4_2__)
    KR8MD_INLINE void store(float *const addr, const pfloat_4 &a)
    {
        _mm_storeu_ps(addr, a);
    }
#endif

#if defined(__AVX2__)
    KR8MD_INLINE void store(float *const addr, const pfloat_8 &a, const pbool32_8 &mask)
    {
        _mm256_maskstore_ps(addr, mask, a);
    }
#endif

#if defined(__AVX2__)
    KR8MD_INLINE void store_aligned(float *const addr, const pfloat_8 &a)
    {
        _mm256_store_ps(addr, a);
    }
#elif defined(__SSE4_2__)
    KR8MD_INLINE void store_aligned(float *const addr, const pfloat_4 &a)
    {
        _mm_store_ps(addr, a);
    }
#endif

#if defined(__AVX2__)
    KR8MD_INLINE void store_unaligned(float *const addr, const pfloat_8 &a)
    {
        _mm256_storeu_ps(addr, a);
    }
#elif defined(__SSE4_2__)
    KR8MD_INLINE void store_unaligned(float *const addr, const pfloat_4 &a)
    {
        _mm_storeu_ps(addr, a);
    }
#endif
} // namespace kr8md