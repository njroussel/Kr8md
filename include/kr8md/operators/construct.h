
#pragma once

#include <krayte/kr8md/pak.h>

namespace kr8md
{
#ifdef __SSE4_2__

    template <>
    KR8MD_INLINE puint32_4::Pak(const uint32_t &value) : intrinsic(_mm_set1_epi32(value)){};

    template <>
    KR8MD_INLINE pint32_4::Pak(const int32_t &value) : intrinsic(_mm_set1_epi32(value)){};

    template <>
    KR8MD_INLINE pfloat_4::Pak(const float &value) : intrinsic(_mm_set1_ps(value)){};
#endif

#ifdef __AVX2__

    template <>
    KR8MD_INLINE puint32_8::Pak(const uint32_t &value) : intrinsic(_mm256_set1_epi32(value)){};

    template <>
    KR8MD_INLINE pint32_8::Pak(const int32_t &value) : intrinsic(_mm256_set1_epi32(value)){};

    template <>
    KR8MD_INLINE pfloat_8::Pak(const float &value) : intrinsic(_mm256_set1_ps(value)){};
#endif
} // namespace kr8md