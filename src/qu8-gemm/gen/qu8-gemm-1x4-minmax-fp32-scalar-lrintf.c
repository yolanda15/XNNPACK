// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/gemm.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/microparams.h"



void xnn_qu8_gemm_minmax_fp32_ukernel_1x4__scalar_lrintf(
    size_t mr,
    size_t nc,
    size_t kc,
    const uint8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    uint8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const union xnn_qu8_conv_minmax_params* restrict params)
{
  assert(mr != 0);
  assert(mr <= 1);
  assert(nc != 0);
  assert(kc != 0);

  const uint8_t* a0 = a;
  uint8_t* c0 = c;

  const int32_t output_min_less_zero_point = (int32_t) params->fp32_scalar.output_min - (int32_t) params->fp32_scalar.output_zero_point;
  const int32_t output_max_less_zero_point = (int32_t) params->fp32_scalar.output_max - (int32_t) params->fp32_scalar.output_zero_point;
  const float vscale = params->fp32_scalar.scale;
  const float voutput_min_less_zero_point = output_min_less_zero_point;
  const float voutput_max_less_zero_point = output_max_less_zero_point;
  const int32_t voutput_zero_point = params->fp32_scalar.output_zero_point;

  const int32_t vb_zero_point = params->fp32_scalar.kernel_zero_point;
  do {
    int32_t vacc0x0 = ((const int32_t*) w)[0];
    int32_t vacc0x1 = ((const int32_t*) w)[1];
    int32_t vacc0x2 = ((const int32_t*) w)[2];
    int32_t vacc0x3 = ((const int32_t*) w)[3];
    w = (const int32_t*) w + 4;

    size_t k = kc;
    do {
      const int32_t va0 = (int32_t) (uint32_t) *a0++;

      const int32_t vb0 = (int32_t) (uint32_t) ((const uint8_t*) w)[0] - vb_zero_point;
      const int32_t vb1 = (int32_t) (uint32_t) ((const uint8_t*) w)[1] - vb_zero_point;
      const int32_t vb2 = (int32_t) (uint32_t) ((const uint8_t*) w)[2] - vb_zero_point;
      const int32_t vb3 = (int32_t) (uint32_t) ((const uint8_t*) w)[3] - vb_zero_point;
      w = (const uint8_t*) w + 4;

      vacc0x0 += va0 * vb0;
      vacc0x1 += va0 * vb1;
      vacc0x2 += va0 * vb2;
      vacc0x3 += va0 * vb3;

      k -= sizeof(uint8_t);
    } while (k != 0);

    float vfpacc0x0 = (float) vacc0x0;
    float vfpacc0x1 = (float) vacc0x1;
    float vfpacc0x2 = (float) vacc0x2;
    float vfpacc0x3 = (float) vacc0x3;

    vfpacc0x0 *= vscale;
    vfpacc0x1 *= vscale;
    vfpacc0x2 *= vscale;
    vfpacc0x3 *= vscale;

    vfpacc0x0 = math_max_f32(vfpacc0x0, voutput_min_less_zero_point);
    vfpacc0x1 = math_max_f32(vfpacc0x1, voutput_min_less_zero_point);
    vfpacc0x2 = math_max_f32(vfpacc0x2, voutput_min_less_zero_point);
    vfpacc0x3 = math_max_f32(vfpacc0x3, voutput_min_less_zero_point);

    vfpacc0x0 = math_min_f32(vfpacc0x0, voutput_max_less_zero_point);
    vfpacc0x1 = math_min_f32(vfpacc0x1, voutput_max_less_zero_point);
    vfpacc0x2 = math_min_f32(vfpacc0x2, voutput_max_less_zero_point);
    vfpacc0x3 = math_min_f32(vfpacc0x3, voutput_max_less_zero_point);

    const int32_t vrndacc0x0 = (int32_t) lrintf(vfpacc0x0);
    const int32_t vrndacc0x1 = (int32_t) lrintf(vfpacc0x1);
    const int32_t vrndacc0x2 = (int32_t) lrintf(vfpacc0x2);
    const int32_t vrndacc0x3 = (int32_t) lrintf(vfpacc0x3);

    int32_t vout0x0 = vrndacc0x0 + voutput_zero_point;
    int32_t vout0x1 = vrndacc0x1 + voutput_zero_point;
    int32_t vout0x2 = vrndacc0x2 + voutput_zero_point;
    int32_t vout0x3 = vrndacc0x3 + voutput_zero_point;

    if XNN_LIKELY(nc >= 4) {
      c0[0] = (uint8_t) vout0x0;
      c0[1] = (uint8_t) vout0x1;
      c0[2] = (uint8_t) vout0x2;
      c0[3] = (uint8_t) vout0x3;

      a0 = (const uint8_t*) ((uintptr_t) a0 - kc);

      c0 = (uint8_t*) ((uintptr_t) c0 + cn_stride);

      nc -= 4;
    } else {
      if (nc & 2) {
        c0[0] = (uint8_t) vout0x0;
        c0[1] = (uint8_t) vout0x1;
        vout0x0 = vout0x2;
        c0 += 2;
      }
      if (nc & 1) {
        c0[0] = (uint8_t) vout0x0;
      }

      nc = 0;
    }
  } while (nc != 0);
}
