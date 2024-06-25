// Auto-generated file. Do not edit!
//   Template: src/i16-vlshift/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "xnnpack/math.h"
#include "xnnpack/vlshift.h"


void xnn_i16_vlshift_ukernel__scalar_u1(
    size_t batch,
    const uint16_t* input,
    uint16_t* output,
    uint32_t shift)
{
  assert(batch != 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(shift < 16);

 if XNN_UNLIKELY(batch != 0) {
   do {
     const uint16_t vi = *input++;
     const uint16_t vout = vi << shift;
     *output++ = vout;
   } while (--batch != 0);
 }
}
