# Kr8md

Header-only SIMD C++ library

## Table of Contents

- [Features](#features)
- [Demo](#demo)

## Features

- Supports SSE4.2 and AVX2

## Demo

```cpp
// Declare pa(c)ked types - their width is determinded at compile-time to match
// the largest possible vector register for the target architecture.
pfloat x = ...;

if any(x > 2.0f) {
  masked(x, x > 2) = x * x; // Use masks to select specific lanes
}
```
