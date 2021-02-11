#pragma once

#include <krayte/kr8md/intrinsic_types.h>

#if defined(__AVX2__) || defined(__SSE4_2__)
#include <immintrin.h>
#endif

namespace kr8md
{
    struct no_intrinsic_cast_t
    {
    };

    template <typename T, size_t W>
    struct intrinsic_cast_t
    {
        using type = no_intrinsic_cast_t;
    };

#ifdef __SSE4_2__
    template <>
    struct intrinsic_cast_t<uint32_t, 4>
    {
        using type = intrinsic_t<float, 4>::type;
    };

    template <>
    struct intrinsic_cast_t<int32_t, 4>
    {
        using type = intrinsic_t<float, 4>::type;
    };

    template <>
    struct intrinsic_cast_t<float, 4>
    {
        using type = intrinsic_t<int32_t, 4>::type;
    };
#endif

#ifdef __AVX2__
    template <>
    struct intrinsic_cast_t<uint32_t, 8>
    {
        using type = intrinsic_t<float, 8>::type;
    };

    template <>
    struct intrinsic_cast_t<int32_t, 8>
    {
        using type = intrinsic_t<float, 8>::type;
    };

    template <>
    struct intrinsic_cast_t<float, 8>
    {
        using type = intrinsic_t<int32_t, 8>::type;
    };
#endif
} // namespace kr8md