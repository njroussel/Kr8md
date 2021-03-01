#pragma once

#include <kr8md/kr8md.h>

#include <iostream>

namespace kr8md {
template <typename T, size_t W>
std::ostream &operator<<(std::ostream &os, const Pak<T, W> &pak) {
  os << "{";
  for (size_t i = 0; i < W; ++i) {
    os << pak.data[i];
    if (i != W - 1) {
      os << ", ";
    }
  }
  os << "}";

  return os;
}

}  // namespace kr8md