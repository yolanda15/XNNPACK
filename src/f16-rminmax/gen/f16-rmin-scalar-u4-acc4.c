// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f16-rminmax/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/reduce.h"


void xnn_f16_rmin_ukernel__scalar_u4_acc4(
    size_t batch,
    const xnn_float16* input,
    xnn_float16* output,
    const struct xnn_f16_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(uint16_t) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const uint16_t* i = (const uint16_t*) input;
  uint16_t* o = (uint16_t*) output;

  int16_t vt = math_signcomplement_f16(*i);
  int16_t vmin0 = vt;
  int16_t vmin1 = vt;
  int16_t vmin2 = vt;
  int16_t vmin3 = vt;
  for (; batch >= 4 * sizeof(uint16_t); batch -= 4 * sizeof(uint16_t)) {
    const int16_t vt0 = math_signcomplement_f16(i[0]);
    const int16_t vt1 = math_signcomplement_f16(i[1]);
    const int16_t vt2 = math_signcomplement_f16(i[2]);
    const int16_t vt3 = math_signcomplement_f16(i[3]);
    i += 4;

    vmin0 = math_min_s16(vmin0, vt0);
    vmin1 = math_min_s16(vmin1, vt1);
    vmin2 = math_min_s16(vmin2, vt2);
    vmin3 = math_min_s16(vmin3, vt3);
  }
  vmin0 = math_min_s16(vmin0, vmin1);
  vmin2 = math_min_s16(vmin2, vmin3);
  vmin0 = math_min_s16(vmin0, vmin2);

  if XNN_UNLIKELY(batch != 0) {
    do {
      vt = math_signcomplement_f16(*i++);
      vmin0 = math_min_s16(vmin0, vt);
      batch -= sizeof(uint16_t);
    } while (batch != 0);
  }
  o[0] = (uint16_t) math_signcomplement_f16((uint16_t) vmin0);
}
