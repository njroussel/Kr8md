#pragma once

#if defined(__AVX2__) || defined(__SSE4_2__)
#include <immintrin.h>
#endif

namespace kr8md
{
    template <typename T, int W>
    struct no_intrinsic_t
    {
        using type = T *;
    };

    template <typename T, size_t W>
    struct intrinsic_t
    {
        using type = no_intrinsic_t<T, W>;
    };

#ifdef __SSE4_2__
    template <>
    struct intrinsic_t<int8_t, 16>
    {
        using type = __m128i;
    };

    template <>
    struct intrinsic_t<uint8_t, 16>
    {
        using type = __m128i;
    };

    template <>
    struct intrinsic_t<int16_t, 8>
    {
        using type = __m128i;
    };

    template <>
    struct intrinsic_t<uint16_t, 8>
    {
        using type = __m128i;
    };

    template <>
    struct intrinsic_t<int32_t, 4>
    {
        using type = __m128i;
    };

    template <>
    struct intrinsic_t<uint32_t, 4>
    {
        using type = __m128i;
    };

    template <>
    struct intrinsic_t<int64_t, 2>
    {
        using type = __m128i;
    };

    template <>
    struct intrinsic_t<uint64_t, 2>
    {
        using type = __m128i;
    };

    template <>
    struct intrinsic_t<float, 4>
    {
        using type = __m128;
    };

    template <>
    struct intrinsic_t<double, 2>
    {
        using type = __m128d;
    };

#endif

#ifdef __AVX2__
    template <>
    struct intrinsic_t<int8_t, 32>
    {
        using type = __m256i;
    };

    template <>
    struct intrinsic_t<uint8_t, 32>
    {
        using type = __m256i;
    };

    template <>
    struct intrinsic_t<int16_t, 16>
    {
        using type = __m256i;
    };

    template <>
    struct intrinsic_t<uint16_t, 16>
    {
        using type = __m256i;
    };

    template <>
    struct intrinsic_t<int32_t, 8>
    {
        using type = __m256i;
    };

    template <>
    struct intrinsic_t<uint32_t, 8>
    {
        using type = __m256i;
    };

    template <>
    struct intrinsic_t<int64_t, 4>
    {
        using type = __m256i;
    };

    template <>
    struct intrinsic_t<uint64_t, 4>
    {
        using type = __m256i;
    };

    template <>
    struct intrinsic_t<float, 8>
    {
        using type = __m256;
    };

    template <>
    struct intrinsic_t<double, 4>
    {
        using type = __m256d;
    };

#endif
} // namespace kr8md