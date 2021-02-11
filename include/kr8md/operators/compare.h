#pragma once

#include <krayte/kr8md/pak.h>
#include <krayte/kr8md/defaults.h>
namespace kr8md
{
    // less-than <

#ifdef __SSE4_2__
    KR8MD_INLINE pbool32_4 operator<(const puint32_4 &a, const puint32_4 &b)
    {
        return _mm_cmplt_epi32(a, b);
    }

    KR8MD_INLINE pbool32_4 operator<(const pint32_4 &a, const pint32_4 &b)
    {
        return _mm_cmplt_epi32(a, b);
    }

    KR8MD_INLINE pbool32_4 operator<(const pfloat_4 &a, const pfloat_4 &b)
    {
        return _mm_cmplt_ps(a, b);
    }
#endif

#ifdef __AVX2__
    KR8MD_INLINE pbool32_8 operator<(const puint32_8 &a, const puint32_8 &b)
    {
        return _mm256_cmpgt_epi32(b, a);
    }

    KR8MD_INLINE pbool32_8 operator<(const pint32_8 &a, const pint32_8 &b)
    {
        return _mm256_cmpgt_epi32(b, a);
    }

    KR8MD_INLINE pbool32_8 operator<(const pfloat_8 &a, const pfloat_8 &b)
    {
        return _mm256_cmp_ps(a, b, _CMP_LT_OQ);
    }
#endif

    // greater-than >

#ifdef __SSE4_2__
    KR8MD_INLINE pbool32_4 operator>(const pfloat_4 &a, const pfloat_4 &b)
    {
        return _mm_cmpgt_ps(a, b);
    }
#endif

#ifdef __AVX2__
    KR8MD_INLINE pbool32_8 operator>(const pfloat_8 &a, const pfloat_8 &b)
    {
        return _mm256_cmp_ps(a, b, _CMP_GT_OQ);
    }
#endif

    // less-than-or-equal <=

#ifdef __SSE4_2__
    KR8MD_INLINE pbool32_4 operator<=(const pfloat_4 &a, const pfloat_4 &b)
    {
        return _mm_cmple_ps(a, b);
    }
#endif

#ifdef __AVX2__
    KR8MD_INLINE pbool32_8 operator<=(const pfloat_8 &a, const pfloat_8 &b)
    {
        return _mm256_cmp_ps(a, b, _CMP_LE_OQ);
    }
#endif

    // greater-than-or-equal <=

#ifdef __SSE4_2__
    KR8MD_INLINE pbool32_4 operator>=(const pfloat_4 &a, const pfloat_4 &b)
    {
        return _mm_cmpge_ps(a, b);
    }
#endif

#ifdef __AVX2__
    KR8MD_INLINE pbool32_8 operator>=(const pfloat_8 &a, const pfloat_8 &b)
    {
        return _mm256_cmp_ps(a, b, _CMP_GE_OQ);
    }
#endif

    // equal ==

#ifdef __SSE4_2__
    KR8MD_INLINE pbool32_4 operator==(const pfloat_4 &a, const pfloat_4 &b)
    {
        return _mm_cmpeq_ps(a, b);
    }
#endif

#ifdef __AVX2__
    KR8MD_INLINE pbool32_8 operator==(const pfloat_8 &a, const pfloat_8 &b)
    {
        return _mm256_cmp_ps(a, b, _CMP_EQ_OQ);
    }
#endif

    // not-equal !=

#ifdef __SSE4_2__
    KR8MD_INLINE pbool32_4 operator!=(const pfloat_4 &a, const pfloat_4 &b)
    {
        return _mm_cmpneq_ps(a, b);
    }
#endif

#ifdef __AVX2__
    KR8MD_INLINE pbool32_8 operator!=(const pfloat_8 &a, const pfloat_8 &b)
    {
        return _mm256_cmp_ps(a, b, _CMP_NEQ_OQ);
    }
#endif
} // namespace kr8md
