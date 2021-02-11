#pragma once

#include <stddef.h>

#include <krayte/kr8md/bool_types.h>
#include <krayte/kr8md/defaults.h>
#include <krayte/kr8md/intrinsic_cast_types.h>
#include <krayte/kr8md/intrinsic_types.h>

namespace kr8md
{
    template <typename T, size_t W = max_supported_width_for_type<T>()>
    struct Pak
    {

        enum
        {
            width = W,
        };

        using intrinsic_t = typename intrinsic_t<T, W>::type;
        using intrinsic_cast_t = typename intrinsic_cast_t<T, W>::type;

        union
        {
            T data[W];
            intrinsic_t intrinsic;
            intrinsic_cast_t intrinsic_cast;
        };

        Pak() {}

        Pak(const intrinsic_t intrinsinc_) : intrinsic(intrinsinc_) {}

        Pak(const intrinsic_cast_t intrinsinc_cast_) : intrinsic_cast(intrinsinc_cast_) {}

        Pak(T const *const arr)
        {
            for (size_t i = 0; i < W; ++i)
            {
                data[i] = arr[i];
            }
        }

        Pak(const T &val)
        {
            for (size_t i = 0; i < W; ++i)
            {
                data[i] = val;
            }
        }

        KR8MD_INLINE operator const intrinsic_t &() const
        {
            return intrinsic;
        }

        KR8MD_INLINE operator intrinsic_t &()
        {
            return intrinsic;
        }

        KR8MD_INLINE operator const intrinsic_cast_t &() const
        {
            return intrinsic_cast;
        }

        KR8MD_INLINE operator intrinsic_cast_t &()
        {
            return intrinsic_cast;
        }

        Pak<T, W> &operator++();
        Pak<T, W> operator++(int);
    };

    template <typename T, size_t W>
    struct MaskedPak
    {
        using TPak = Pak<T, W>;
        using intrinsic_t = typename TPak::intrinsic_t;
        using mask_t = typename bool_t<T>::type;
        using MaskPak = Pak<mask_t, W>;

        TPak &pak;
        const MaskPak &mask;

        MaskedPak() {}

        MaskedPak(TPak &pak_, const MaskPak &mask_) : pak(pak_), mask(mask_) {}

        KR8MD_INLINE void operator=(const TPak &rhs)
        {
            pak = select(mask, pak, rhs);
        }
    };

    template <typename T, size_t W>
    KR8MD_INLINE MaskedPak<T, W> masked(Pak<T, W> &pak, const Pak<typename bool_t<T>::type, W> &mask)
    {
        return MaskedPak<T, W>{pak, mask};
    }

    using pbool32 = Pak<uint32_t>;
    using puint32 = Pak<uint32_t>;
    using pint32 = Pak<int32_t>;
    using pfloat = Pak<float>;
    using pdouble = Pak<double>;

    template <size_t W>
    using pbool32_n = Pak<uint32_t, W>;
    template <size_t W>
    using puint32_n = Pak<uint32_t, W>;
    template <size_t W>
    using pint32_n = Pak<int32_t, W>;
    template <size_t W>
    using pfloat_n = Pak<float, W>;
    template <size_t W>
    using pdouble_n = Pak<double, W>;

    using pbool32_4 = pbool32_n<4>;
    using puint32_4 = puint32_n<4>;
    using pint32_4 = pint32_n<4>;
    using pfloat_4 = pfloat_n<4>;

    using pbool32_8 = pbool32_n<8>;
    using puint32_8 = puint32_n<8>;
    using pint32_8 = pint32_n<8>;
    using pfloat_8 = pfloat_n<8>;
} // namespace kr8md