// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-vcvt/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/math.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/vcvt.h"


void xnn_qs8_vcvt_ukernel__scalar_u1(
    size_t batch,
    const int8_t* input,
    int8_t* output,
    const struct xnn_qs8_cvt_params* restrict params)
{
  assert(batch != 0);
  assert(batch % sizeof(int8_t) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const int32_t vbias =
      (int32_t) (((uint32_t) (int32_t) params->scalar.output_zero_point) << 8) -
      (int32_t) params->scalar.multiplier * (int32_t) params->scalar.input_zero_point +
      INT32_C(0x80);
  const int32_t vmultiplier = params->scalar.multiplier;
  do {
    int32_t vacc = *input++;
    vacc = vbias + vacc * vmultiplier;

    int32_t vout = math_asr_s32(vacc, 8);
    vout = math_max_s32(vout, -128);
    vout = math_min_s32(vout, 127);
    *output++ = (int8_t) vout;

    batch -= sizeof(int8_t);
  } while (batch != 0);
}
