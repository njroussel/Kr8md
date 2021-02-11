#pragma once

#include <krayte/kr8md/pak.h>
#include <krayte/kr8md/defaults.h>

namespace kr8md
{
#ifdef __SSE4_2__
    KR8MD_INLINE puint32_4 operator+(const puint32_4 &a, const puint32_4 &b)
    {
        return _mm_add_epi32(a, b);
    }

    KR8MD_INLINE pint32_4 operator+(const pint32_4 &a, const pint32_4 &b)
    {
        return _mm_add_epi32(a, b);
    }

    KR8MD_INLINE pfloat_4 operator+(const pfloat_4 &a, const pfloat_4 &b)
    {
        return _mm_add_ps(a, b);
    }
#endif

#ifdef __AVX2__
    KR8MD_INLINE puint32_8 operator+(const puint32_8 &a, const puint32_8 &b)
    {
        return _mm256_add_epi32(a, b);
    }

    KR8MD_INLINE pint32_8 operator+(const pint32_8 &a, const pint32_8 &b)
    {
        return _mm256_add_epi32(a, b);
    }

    KR8MD_INLINE pfloat_8 operator+(const pfloat_8 &a, const pfloat_8 &b)
    {
        return _mm256_add_ps(a, b);
    }
#endif
} // namespace kr8md