#pragma once

#include <krayte/kr8md/pak.h>
#include <krayte/kr8md/defaults.h>

namespace kr8md
{
#ifdef __SSE4_2__
    template <>
    KR8MD_INLINE puint32_4 &puint32_4::operator++()
    {
        this->intrinsic = _mm_add_epi32(*this, _mm_set1_epi32(1));
        return *this;
    }

    template <>
    KR8MD_INLINE puint32_4 puint32_4::operator++(int)
    {
        puint32_4 tmp = *this;
        ++*this;
        return tmp;
    }

    template <>
    KR8MD_INLINE pint32_4 &pint32_4::operator++()
    {
        this->intrinsic = _mm_add_epi32(*this, _mm_set1_epi32(1));
        return *this;
    }

    template <>
    KR8MD_INLINE pint32_4 pint32_4::operator++(int)
    {
        pint32_4 tmp = *this;
        ++*this;
        return tmp;
    }

    template <>
    KR8MD_INLINE pfloat_4 &pfloat_4::operator++()
    {
        this->intrinsic = _mm_add_ps(*this, _mm_set1_ps(1));
        return *this;
    }

    template <>
    KR8MD_INLINE pfloat_4 pfloat_4::operator++(int)
    {
        pfloat_4 tmp = *this;
        ++*this;
        return tmp;
    }
#endif

#ifdef __AVX2__
    template <>
    KR8MD_INLINE puint32_8 &puint32_8::operator++()
    {
        this->intrinsic = _mm256_add_epi32(*this, _mm256_set1_epi32(1));
        return *this;
    }

    template <>
    KR8MD_INLINE puint32_8 puint32_8::operator++(int)
    {
        puint32_8 tmp = *this;
        ++*this;
        return tmp;
    }

    template <>
    KR8MD_INLINE pint32_8 &pint32_8::operator++()
    {
        this->intrinsic = _mm256_add_epi32(*this, _mm256_set1_epi32(1));
        return *this;
    }

    template <>
    KR8MD_INLINE pint32_8 pint32_8::operator++(int)
    {
        pint32_8 tmp = *this;
        ++*this;
        return tmp;
    }

    template <>
    KR8MD_INLINE pfloat_8 &pfloat_8::operator++()
    {
        this->intrinsic = _mm256_add_ps(*this, _mm256_set1_ps(1));
        return *this;
    }

    template <>
    KR8MD_INLINE pfloat_8 pfloat_8::operator++(int)
    {
        pfloat_8 tmp = *this;
        ++*this;
        return tmp;
    }
#endif
} // namespace kr8md