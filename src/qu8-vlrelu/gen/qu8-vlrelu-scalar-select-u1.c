// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-vlrelu/scalar-select.c.in
//   Generator: tools/xngen
//
// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include "src/xnnpack/math.h"
#include "src/xnnpack/vunary.h"


void xnn_qu8_vlrelu_ukernel__scalar_select_u1(
    size_t batch,
    const uint8_t* input,
    uint8_t* output,
    const struct xnn_qu8_lrelu_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(uint8_t) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const int32_t vinput_zero_point = params->scalar.input_zero_point;
  const int32_t vpositive_multiplier = params->scalar.positive_multiplier;
  const int32_t vnegative_multiplier = params->scalar.negative_multiplier;
  const int32_t vbias = (int32_t) (((uint32_t) (int32_t) params->scalar.output_zero_point) << 8) + 0x80;
  do {
    int32_t vacc = (int32_t) *input++ - vinput_zero_point;
    const int32_t vmultiplier = XNN_UNPREDICTABLE(vacc >= 0) ? vpositive_multiplier : vnegative_multiplier;
    vacc = vbias + vacc * vmultiplier;

    int32_t vout = math_asr_s32(vacc, 8);
    vout = math_max_s32(vout, 0);
    vout = math_min_s32(vout, 255);
    *output++ = (uint8_t) vout;

    batch -= sizeof(uint8_t);
  } while (batch != 0);
}
