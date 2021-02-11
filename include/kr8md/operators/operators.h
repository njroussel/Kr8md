#pragma once

/*
    Almost all operators are defined exclusively for the SSE4.2 and AVX2
    instruction sets. There are, currently, no fallbacks if there is no
    intrinsic corresponding to the operator. This allows us to generate
    compile-time errors and ensure that there aren't any optimal packed
    instructions that aren't yet implemented.
*/

#include <kr8md/operators/add.h>
#include <kr8md/operators/any.h>
#include <kr8md/operators/compare.h>
#include <kr8md/operators/construct.h>
#include <kr8md/operators/divide.h>
#include <kr8md/operators/increment.h>
#include <kr8md/operators/load.h>
#include <kr8md/operators/multiply.h>
#include <kr8md/operators/select.h>
#include <kr8md/operators/store.h>
#include <kr8md/operators/subtract.h>