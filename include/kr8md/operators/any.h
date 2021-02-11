#pragma once

#include <krayte/kr8md/pak.h>
#include <krayte/kr8md/defaults.h>

namespace kr8md
{
#ifdef __SSE4_2__
    KR8MD_INLINE bool any(const pbool32_4 &a)
    {
        return _mm_movemask_ps(a) != 0;
    }
#endif

#ifdef __AVX2__
    KR8MD_INLINE bool any(const pbool32_8 &a)
    {
        return !_mm256_testz_ps(a, a);
    }
#endif
} // namespace kr8md