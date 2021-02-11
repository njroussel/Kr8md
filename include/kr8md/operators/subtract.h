#pragma once

#include <krayte/kr8md/pak.h>
#include <krayte/kr8md/defaults.h>

namespace kr8md
{
#ifdef __SSE4_2__
    KR8MD_INLINE pfloat_4 operator-(const pfloat_4 &a, const pfloat_4 &b)
    {
        return _mm_sub_ps(a, b);
    }
#endif

#ifdef __AVX2__
    KR8MD_INLINE pfloat_8 operator-(const pfloat_8 &a, const pfloat_8 &b)
    {
        return _mm256_sub_ps(a, b);
    }
#endif
} // namespace kr8md
