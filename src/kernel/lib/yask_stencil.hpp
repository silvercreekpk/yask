/*****************************************************************************

YASK: Yet Another Stencil Kernel
Copyright (c) 2014-2018, Intel Corporation

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

*****************************************************************************/

// This file defines functions, types, and macros needed for the stencil
// kernel.

#pragma once

// Stencil-independent definitions.
#include "yask.hpp"

// Auto-generated macros from foldBuilder.  It's important that this be
// included before the definitions below to properly set the vector lengths,
// etc.
#define DEFINE_MACROS
#include YSTR2(YK_CODE_FILE)
#undef DEFINE_MACROS

// Max number of dims allowed in Indices.
// TODO: make Indices a templated class based on
// number of dims.
#ifndef MAX_DIMS
#if NUM_GRID_DIMS >= NUM_STENCIL_DIMS
#define MAX_DIMS NUM_GRID_DIMS
#else
#define MAX_DIMS NUM_STENCIL_DIMS
#endif
#endif

// First/last index macros.
// These are relative to global problem, not rank.
#define FIRST_INDEX(dim) (0)
#define LAST_INDEX(dim) (_context->overall_domain_sizes[DOMAIN_DIM_IDX_ ## dim] - 1)

// Macros for 1D<->nD transforms.
#include "yask_layout_macros.hpp"

// Define a folded vector of reals.
#include "realv.hpp"

// Base types for stencil context, etc.
#include "settings.hpp"
#include "generic_grids.hpp"
#include "realv_grids.hpp"
#include "context.hpp"
#include "auto_tuner.hpp"
#include "stencil_calc.hpp"
