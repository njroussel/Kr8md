#pragma once

#include <stddef.h>

#if defined(__AVX2__)
#define KR8MD_MAX_VEC_REGISTER_SIZE 32
#elif defined(__SSE4_2__)
#define KR8MD_MAX_VEC_REGISTER_SIZE 16
#else
#define KR8MD_MAX_VEC_REGISTER_SIZE -1
#endif

#define KR8MD_INLINE inline __attribute__((always_inline))

template <typename T>
constexpr size_t max_supported_width_for_type()
{
    if (KR8MD_MAX_VEC_REGISTER_SIZE == -1)
    {
        return 1;
    }

    return KR8MD_MAX_VEC_REGISTER_SIZE / sizeof(T);
}
