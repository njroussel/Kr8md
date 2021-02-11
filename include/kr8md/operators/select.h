#pragma once

#include <krayte/kr8md/pak.h>
#include <krayte/kr8md/defaults.h>

namespace kr8md
{
#ifdef __SSE4_2__
    KR8MD_INLINE pbool32_4 select(const pbool32_4 &mask, const pbool32_4 &a, const pbool32_4 &b)
    {
        return _mm_blendv_epi8(a, b, mask);
    }

    KR8MD_INLINE pbool32_4 select(const pbool32_4 &mask, const pint32_4 &a, const pint32_4 &b)
    {
        return _mm_blendv_epi8(a, b, mask);
    }

    KR8MD_INLINE pfloat_4 select(const pbool32_4 &mask, const pfloat_4 &a, const pfloat_4 &b)
    {
        return _mm_blendv_ps(a, b, mask);
    }
#endif

#ifdef __AVX2__
    KR8MD_INLINE pbool32_8 select(const pbool32_8 &mask, const pbool32_8 &a, const pbool32_8 &b)
    {
        return _mm256_blendv_epi8(a, b, mask);
    }

    KR8MD_INLINE pint32_8 select(const pbool32_8 &mask, const pint32_8 &a, const pint32_8 &b)
    {
        return _mm256_blendv_epi8(a, b, mask);
    }

    KR8MD_INLINE pfloat_8 select(const pbool32_8 &mask, const pfloat_8 &a, const pfloat_8 &b)
    {
        return _mm256_blendv_ps(a, b, mask);
    }
#endif
} // namespace kr8md
