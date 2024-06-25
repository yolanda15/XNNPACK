// Auto-generated file. Do not edit!
//   Template: src/f32-vbinary/vop-wasmsimd.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include "xnnpack/common.h"
#include "xnnpack/vbinary.h"


void xnn_f32_vmul_minmax_ukernel__wasmsimd_x86_u8(
    size_t batch,
    const float* input_a,
    const float* input_b,
    float* output,
    const union xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input_a != NULL);
  assert(input_b != NULL);
  assert(output != NULL);

  const v128_t voutput_min = wasm_v128_load64_splat(params->wasmsimd.min);
  const v128_t voutput_max = wasm_v128_load64_splat(params->wasmsimd.max);

  for (; batch >= 8 * sizeof(float); batch -= 8 * sizeof(float)) {
    const v128_t va0 = wasm_v128_load(input_a);
    const v128_t va1 = wasm_v128_load(input_a + 4);
    input_a += 8;

    const v128_t vb0 = wasm_v128_load(input_b);
    const v128_t vb1 = wasm_v128_load(input_b + 4);
    input_b += 8;

    v128_t vacc0 = wasm_f32x4_mul(va0, vb0);
    v128_t vacc1 = wasm_f32x4_mul(va1, vb1);


    vacc0 = wasm_f32x4_pmax(voutput_min, vacc0);
    vacc1 = wasm_f32x4_pmax(voutput_min, vacc1);

    vacc0 = wasm_f32x4_pmin(voutput_max, vacc0);
    vacc1 = wasm_f32x4_pmin(voutput_max, vacc1);

    wasm_v128_store(output, vacc0);
    wasm_v128_store(output + 4, vacc1);
    output += 8;
  }
  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    const v128_t va = wasm_v128_load(input_a);
    input_a += 4;

    const v128_t vb = wasm_v128_load(input_b);
    input_b += 4;

    v128_t vacc = wasm_f32x4_mul(va, vb);

    vacc = wasm_f32x4_pmax(voutput_min, vacc);
    vacc = wasm_f32x4_pmin(voutput_max, vacc);

    wasm_v128_store(output, vacc);
    output += 4;
  }
  if XNN_UNLIKELY(batch != 0) {
    const v128_t va = wasm_v128_load(input_a);
    const v128_t vb = wasm_v128_load(input_b);

    v128_t vacc = wasm_f32x4_mul(va, vb);

    vacc = wasm_f32x4_pmax(voutput_min, vacc);
    vacc = wasm_f32x4_pmin(voutput_max, vacc);

    if (batch & (2 * sizeof(float))) {
      wasm_v128_store64_lane(output, vacc, 0);
      vacc = wasm_v64x2_shuffle(vacc, vacc, 1, 1);
      output += 2;
    }
    if (batch & (1 * sizeof(float))) {
      wasm_v128_store32_lane(output, vacc, 0);
    }
  }
}
