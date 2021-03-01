#pragma once

#include <kr8md/defaults.h>
#include <kr8md/pak.h>

namespace kr8md {
#ifdef __SSE4_2__
KR8MD_INLINE pfloat_4 operator*(const pfloat_4 &a, const pfloat_4 &b) {
  return _mm_mul_ps(a, b);
}
#endif

#ifdef __AVX2__
KR8MD_INLINE pfloat_8 operator*(const pfloat_8 &a, const pfloat_8 &b) {
  return _mm256_mul_ps(a, b);
}
#endif
}  // namespace kr8md