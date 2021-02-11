#pragma once

#include <stddef.h>

namespace kr8md
{
    struct no_bool_type
    {
    };

    template <typename T>
    struct bool_t
    {
        using type = no_bool_type;
    };

    template <>
    struct bool_t<uint32_t>
    {
        using type = uint32_t;
    };

    template <>
    struct bool_t<int32_t>
    {
        using type = uint32_t;
    };

    template <>
    struct bool_t<float>
    {
        using type = uint32_t;
    };
}