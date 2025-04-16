// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f16-vsin/rational-3-2.c.in
//   Generator: tools/xngen
//
// Copyright 2025 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/simd/f16-avx512fp16.h"

#include "src/xnnpack/common.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/vunary.h"


void xnn_f16_vcos_ukernel__avx512fp16_rational_3_2_div_u32(
    size_t batch,
    const xnn_float16* input,
    xnn_float16* output,
    const struct xnn_f16_default_params unused_params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(xnn_float16) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f16 == 32);

  // Some mathematical constants. We don't use pre-defined macros to ensure
  // that they are rounded exactly as we expect them to be.
  XNN_SIMD_CONST_F16_FROM_FLOAT(vpi, 3.140625f);  // M_PI
  XNN_SIMD_CONST_F16_FROM_FLOAT(v2pi_inv, 0.15917969f); // 0.5 / M_PI
  XNN_SIMD_CONST_F16_FROM_FLOAT(vpi_half, 1.5703125f);  // M_PI / 2

  // The following two values sum to 2*Pi with ~33 bits of accuracy. We use
  // them to accurately subtract integer multiples of 2*Pi from large inputs.
  XNN_SIMD_CONST_F16_FROM_FLOAT(v2pi_hi, 6.25f);  // 2.0 * M_PI (first 5 bits of mantissa)
  XNN_SIMD_CONST_F16_FROM_FLOAT(v2pi_lo, 3.3172607e-2f);  // 2.0 * M_PI (remaining bits)

  // The monomial coefficients of the numerator polynomial (odd,
  // `valpha_1` = `vone`).
  XNN_SIMD_CONST_F16_FROM_FLOAT(valpha_3, -1.1200523376e-01f);

  // The monomial coefficients of the denominator polynomial (even,
  // `vbeta_0` = `vone`).
  XNN_SIMD_CONST_F16_FROM_FLOAT(vbeta_2, 5.5543992668e-02f);

  // Some useful constants.
  XNN_SIMD_CONST_F16_FROM_FLOAT(vone, 1.0f);

  for (; batch >= xnn_simd_bytes_f16; batch -= xnn_simd_bytes_f16) {
    xnn_simd_f16_t vx = xnn_loadu_f16(input);
    input += xnn_simd_size_f16;

    // Map the inputs to the interpolation range.
    xnn_simd_f16_t vx_div_2pi = xnn_mul_f16(vx, v2pi_inv);
    vx_div_2pi = xnn_round_f16(vx_div_2pi);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_hi, vx);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_lo, vx);
    vx = xnn_sub_f16(vpi_half, vx);
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));
    vx = xnn_max_f16(vx, xnn_sub_f16(xnn_neg_f16(vpi), vx));
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));

    // Since the polynomials are odd/even, we need x^2.
    const xnn_simd_f16_t vx2 = xnn_mul_f16(vx, vx);

    // Evaluate the numerator polynomial p.
    xnn_simd_f16_t vp = xnn_fmadd_f16(vx2, valpha_3, vone);
    vp = xnn_mul_f16(vx, vp);

    // Evaluate the denominator polynomial q.
    xnn_simd_f16_t vq = xnn_fmadd_f16(vx2, vbeta_2, vone);

    // Divide the numerator by the denominator.
    const xnn_simd_f16_t vy =  xnn_div_f16(vp, vq);

    xnn_storeu_f16(output, vy);
    output += xnn_simd_size_f16;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_f16_t vx = xnn_load_tail_f16(input, batch >> XNN_LOG2_SIZEOF_UINT16_T);

    // Map the inputs to the interpolation range.
    xnn_simd_f16_t vx_div_2pi = xnn_mul_f16(vx, v2pi_inv);
    vx_div_2pi = xnn_round_f16(vx_div_2pi);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_hi, vx);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_lo, vx);
    vx = xnn_sub_f16(vpi_half, vx);
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));
    vx = xnn_max_f16(vx, xnn_sub_f16(xnn_neg_f16(vpi), vx));
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));

    // Since the polynomials are odd/even, we need x^2.
    const xnn_simd_f16_t vx2 = xnn_mul_f16(vx, vx);

    // Evaluate the numerator polynomial p.
    xnn_simd_f16_t vp = xnn_fmadd_f16(vx2, valpha_3, vone);
    vp = xnn_mul_f16(vx, vp);

    // Evaluate the denominator polynomial q.
    xnn_simd_f16_t vq = xnn_fmadd_f16(vx2, vbeta_2, vone);

    // Divide the numerator by the denominator.
    const xnn_simd_f16_t vy =  xnn_div_f16(vp, vq);

    xnn_store_tail_f16(output, vy, batch >> XNN_LOG2_SIZEOF_UINT16_T);
  }
}

void xnn_f16_vcos_ukernel__avx512fp16_rational_3_2_div_u64(
    size_t batch,
    const xnn_float16* input,
    xnn_float16* output,
    const struct xnn_f16_default_params unused_params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(xnn_float16) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f16 == 32);

  // Some mathematical constants. We don't use pre-defined macros to ensure
  // that they are rounded exactly as we expect them to be.
  XNN_SIMD_CONST_F16_FROM_FLOAT(vpi, 3.140625f);  // M_PI
  XNN_SIMD_CONST_F16_FROM_FLOAT(v2pi_inv, 0.15917969f); // 0.5 / M_PI
  XNN_SIMD_CONST_F16_FROM_FLOAT(vpi_half, 1.5703125f);  // M_PI / 2

  // The following two values sum to 2*Pi with ~33 bits of accuracy. We use
  // them to accurately subtract integer multiples of 2*Pi from large inputs.
  XNN_SIMD_CONST_F16_FROM_FLOAT(v2pi_hi, 6.25f);  // 2.0 * M_PI (first 5 bits of mantissa)
  XNN_SIMD_CONST_F16_FROM_FLOAT(v2pi_lo, 3.3172607e-2f);  // 2.0 * M_PI (remaining bits)

  // The monomial coefficients of the numerator polynomial (odd,
  // `valpha_1` = `vone`).
  XNN_SIMD_CONST_F16_FROM_FLOAT(valpha_3, -1.1200523376e-01f);

  // The monomial coefficients of the denominator polynomial (even,
  // `vbeta_0` = `vone`).
  XNN_SIMD_CONST_F16_FROM_FLOAT(vbeta_2, 5.5543992668e-02f);

  // Some useful constants.
  XNN_SIMD_CONST_F16_FROM_FLOAT(vone, 1.0f);

  for (; batch >= 64 * sizeof(xnn_float16); batch -= 64 * sizeof(xnn_float16)) {
    xnn_simd_f16_t vx_0 = xnn_loadu_f16(input);
    xnn_simd_f16_t vx_1 = xnn_loadu_f16(input + 1 * xnn_simd_size_f16);
    input += 64;

    // Map the inputs to the interpolation range.
    xnn_simd_f16_t vx_div_2pi_0 = xnn_mul_f16(vx_0, v2pi_inv);
    xnn_simd_f16_t vx_div_2pi_1 = xnn_mul_f16(vx_1, v2pi_inv);
    vx_div_2pi_0 = xnn_round_f16(vx_div_2pi_0);
    vx_div_2pi_1 = xnn_round_f16(vx_div_2pi_1);
    vx_0 = xnn_fnmadd_f16(vx_div_2pi_0, v2pi_hi, vx_0);
    vx_1 = xnn_fnmadd_f16(vx_div_2pi_1, v2pi_hi, vx_1);
    vx_0 = xnn_fnmadd_f16(vx_div_2pi_0, v2pi_lo, vx_0);
    vx_1 = xnn_fnmadd_f16(vx_div_2pi_1, v2pi_lo, vx_1);
    vx_0 = xnn_sub_f16(vpi_half, vx_0);
    vx_1 = xnn_sub_f16(vpi_half, vx_1);
    vx_0 = xnn_min_f16(vx_0, xnn_sub_f16(vpi, vx_0));
    vx_1 = xnn_min_f16(vx_1, xnn_sub_f16(vpi, vx_1));
    vx_0 = xnn_max_f16(vx_0, xnn_sub_f16(xnn_neg_f16(vpi), vx_0));
    vx_1 = xnn_max_f16(vx_1, xnn_sub_f16(xnn_neg_f16(vpi), vx_1));
    vx_0 = xnn_min_f16(vx_0, xnn_sub_f16(vpi, vx_0));
    vx_1 = xnn_min_f16(vx_1, xnn_sub_f16(vpi, vx_1));

    // Since the polynomials are odd/even, we need x^2.
    const xnn_simd_f16_t vx2_0 = xnn_mul_f16(vx_0, vx_0);
    const xnn_simd_f16_t vx2_1 = xnn_mul_f16(vx_1, vx_1);

    // Evaluate the numerator polynomial p.
    xnn_simd_f16_t vp_0 = xnn_fmadd_f16(vx2_0, valpha_3, vone);
    xnn_simd_f16_t vp_1 = xnn_fmadd_f16(vx2_1, valpha_3, vone);
    vp_0 = xnn_mul_f16(vx_0, vp_0);
    vp_1 = xnn_mul_f16(vx_1, vp_1);

    // Evaluate the denominator polynomial q.
    xnn_simd_f16_t vq_0 = xnn_fmadd_f16(vx2_0, vbeta_2, vone);
    xnn_simd_f16_t vq_1 = xnn_fmadd_f16(vx2_1, vbeta_2, vone);

    // Divide the numerator by the denominator.
    const xnn_simd_f16_t vy_0 = xnn_div_f16(vp_0, vq_0);
    const xnn_simd_f16_t vy_1 = xnn_div_f16(vp_1, vq_1);

    xnn_storeu_f16(output, vy_0);
    xnn_storeu_f16(output + 1 * xnn_simd_size_f16, vy_1);
    output += 64;
  }
  for (; batch >= xnn_simd_bytes_f16; batch -= xnn_simd_bytes_f16) {
    xnn_simd_f16_t vx = xnn_loadu_f16(input);
    input += xnn_simd_size_f16;

    // Map the inputs to the interpolation range.
    xnn_simd_f16_t vx_div_2pi = xnn_mul_f16(vx, v2pi_inv);
    vx_div_2pi = xnn_round_f16(vx_div_2pi);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_hi, vx);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_lo, vx);
    vx = xnn_sub_f16(vpi_half, vx);
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));
    vx = xnn_max_f16(vx, xnn_sub_f16(xnn_neg_f16(vpi), vx));
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));

    // Since the polynomials are odd/even, we need x^2.
    const xnn_simd_f16_t vx2 = xnn_mul_f16(vx, vx);

    // Evaluate the numerator polynomial p.
    xnn_simd_f16_t vp = xnn_fmadd_f16(vx2, valpha_3, vone);
    vp = xnn_mul_f16(vx, vp);

    // Evaluate the denominator polynomial q.
    xnn_simd_f16_t vq = xnn_fmadd_f16(vx2, vbeta_2, vone);

    // Divide the numerator by the denominator.
    const xnn_simd_f16_t vy =  xnn_div_f16(vp, vq);

    xnn_storeu_f16(output, vy);
    output += xnn_simd_size_f16;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_f16_t vx = xnn_load_tail_f16(input, batch >> XNN_LOG2_SIZEOF_UINT16_T);

    // Map the inputs to the interpolation range.
    xnn_simd_f16_t vx_div_2pi = xnn_mul_f16(vx, v2pi_inv);
    vx_div_2pi = xnn_round_f16(vx_div_2pi);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_hi, vx);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_lo, vx);
    vx = xnn_sub_f16(vpi_half, vx);
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));
    vx = xnn_max_f16(vx, xnn_sub_f16(xnn_neg_f16(vpi), vx));
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));

    // Since the polynomials are odd/even, we need x^2.
    const xnn_simd_f16_t vx2 = xnn_mul_f16(vx, vx);

    // Evaluate the numerator polynomial p.
    xnn_simd_f16_t vp = xnn_fmadd_f16(vx2, valpha_3, vone);
    vp = xnn_mul_f16(vx, vp);

    // Evaluate the denominator polynomial q.
    xnn_simd_f16_t vq = xnn_fmadd_f16(vx2, vbeta_2, vone);

    // Divide the numerator by the denominator.
    const xnn_simd_f16_t vy =  xnn_div_f16(vp, vq);

    xnn_store_tail_f16(output, vy, batch >> XNN_LOG2_SIZEOF_UINT16_T);
  }
}

void xnn_f16_vcos_ukernel__avx512fp16_rational_3_2_div_u96(
    size_t batch,
    const xnn_float16* input,
    xnn_float16* output,
    const struct xnn_f16_default_params unused_params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(xnn_float16) == 0);
  assert(input != NULL);
  assert(output != NULL);
  assert(xnn_simd_size_f16 == 32);

  // Some mathematical constants. We don't use pre-defined macros to ensure
  // that they are rounded exactly as we expect them to be.
  XNN_SIMD_CONST_F16_FROM_FLOAT(vpi, 3.140625f);  // M_PI
  XNN_SIMD_CONST_F16_FROM_FLOAT(v2pi_inv, 0.15917969f); // 0.5 / M_PI
  XNN_SIMD_CONST_F16_FROM_FLOAT(vpi_half, 1.5703125f);  // M_PI / 2

  // The following two values sum to 2*Pi with ~33 bits of accuracy. We use
  // them to accurately subtract integer multiples of 2*Pi from large inputs.
  XNN_SIMD_CONST_F16_FROM_FLOAT(v2pi_hi, 6.25f);  // 2.0 * M_PI (first 5 bits of mantissa)
  XNN_SIMD_CONST_F16_FROM_FLOAT(v2pi_lo, 3.3172607e-2f);  // 2.0 * M_PI (remaining bits)

  // The monomial coefficients of the numerator polynomial (odd,
  // `valpha_1` = `vone`).
  XNN_SIMD_CONST_F16_FROM_FLOAT(valpha_3, -1.1200523376e-01f);

  // The monomial coefficients of the denominator polynomial (even,
  // `vbeta_0` = `vone`).
  XNN_SIMD_CONST_F16_FROM_FLOAT(vbeta_2, 5.5543992668e-02f);

  // Some useful constants.
  XNN_SIMD_CONST_F16_FROM_FLOAT(vone, 1.0f);

  for (; batch >= 96 * sizeof(xnn_float16); batch -= 96 * sizeof(xnn_float16)) {
    xnn_simd_f16_t vx_0 = xnn_loadu_f16(input);
    xnn_simd_f16_t vx_1 = xnn_loadu_f16(input + 1 * xnn_simd_size_f16);
    xnn_simd_f16_t vx_2 = xnn_loadu_f16(input + 2 * xnn_simd_size_f16);
    input += 96;

    // Map the inputs to the interpolation range.
    xnn_simd_f16_t vx_div_2pi_0 = xnn_mul_f16(vx_0, v2pi_inv);
    xnn_simd_f16_t vx_div_2pi_1 = xnn_mul_f16(vx_1, v2pi_inv);
    xnn_simd_f16_t vx_div_2pi_2 = xnn_mul_f16(vx_2, v2pi_inv);
    vx_div_2pi_0 = xnn_round_f16(vx_div_2pi_0);
    vx_div_2pi_1 = xnn_round_f16(vx_div_2pi_1);
    vx_div_2pi_2 = xnn_round_f16(vx_div_2pi_2);
    vx_0 = xnn_fnmadd_f16(vx_div_2pi_0, v2pi_hi, vx_0);
    vx_1 = xnn_fnmadd_f16(vx_div_2pi_1, v2pi_hi, vx_1);
    vx_2 = xnn_fnmadd_f16(vx_div_2pi_2, v2pi_hi, vx_2);
    vx_0 = xnn_fnmadd_f16(vx_div_2pi_0, v2pi_lo, vx_0);
    vx_1 = xnn_fnmadd_f16(vx_div_2pi_1, v2pi_lo, vx_1);
    vx_2 = xnn_fnmadd_f16(vx_div_2pi_2, v2pi_lo, vx_2);
    vx_0 = xnn_sub_f16(vpi_half, vx_0);
    vx_1 = xnn_sub_f16(vpi_half, vx_1);
    vx_2 = xnn_sub_f16(vpi_half, vx_2);
    vx_0 = xnn_min_f16(vx_0, xnn_sub_f16(vpi, vx_0));
    vx_1 = xnn_min_f16(vx_1, xnn_sub_f16(vpi, vx_1));
    vx_2 = xnn_min_f16(vx_2, xnn_sub_f16(vpi, vx_2));
    vx_0 = xnn_max_f16(vx_0, xnn_sub_f16(xnn_neg_f16(vpi), vx_0));
    vx_1 = xnn_max_f16(vx_1, xnn_sub_f16(xnn_neg_f16(vpi), vx_1));
    vx_2 = xnn_max_f16(vx_2, xnn_sub_f16(xnn_neg_f16(vpi), vx_2));
    vx_0 = xnn_min_f16(vx_0, xnn_sub_f16(vpi, vx_0));
    vx_1 = xnn_min_f16(vx_1, xnn_sub_f16(vpi, vx_1));
    vx_2 = xnn_min_f16(vx_2, xnn_sub_f16(vpi, vx_2));

    // Since the polynomials are odd/even, we need x^2.
    const xnn_simd_f16_t vx2_0 = xnn_mul_f16(vx_0, vx_0);
    const xnn_simd_f16_t vx2_1 = xnn_mul_f16(vx_1, vx_1);
    const xnn_simd_f16_t vx2_2 = xnn_mul_f16(vx_2, vx_2);

    // Evaluate the numerator polynomial p.
    xnn_simd_f16_t vp_0 = xnn_fmadd_f16(vx2_0, valpha_3, vone);
    xnn_simd_f16_t vp_1 = xnn_fmadd_f16(vx2_1, valpha_3, vone);
    xnn_simd_f16_t vp_2 = xnn_fmadd_f16(vx2_2, valpha_3, vone);
    vp_0 = xnn_mul_f16(vx_0, vp_0);
    vp_1 = xnn_mul_f16(vx_1, vp_1);
    vp_2 = xnn_mul_f16(vx_2, vp_2);

    // Evaluate the denominator polynomial q.
    xnn_simd_f16_t vq_0 = xnn_fmadd_f16(vx2_0, vbeta_2, vone);
    xnn_simd_f16_t vq_1 = xnn_fmadd_f16(vx2_1, vbeta_2, vone);
    xnn_simd_f16_t vq_2 = xnn_fmadd_f16(vx2_2, vbeta_2, vone);

    // Divide the numerator by the denominator.
    const xnn_simd_f16_t vy_0 = xnn_div_f16(vp_0, vq_0);
    const xnn_simd_f16_t vy_1 = xnn_div_f16(vp_1, vq_1);
    const xnn_simd_f16_t vy_2 = xnn_div_f16(vp_2, vq_2);

    xnn_storeu_f16(output, vy_0);
    xnn_storeu_f16(output + 1 * xnn_simd_size_f16, vy_1);
    xnn_storeu_f16(output + 2 * xnn_simd_size_f16, vy_2);
    output += 96;
  }
  for (; batch >= xnn_simd_bytes_f16; batch -= xnn_simd_bytes_f16) {
    xnn_simd_f16_t vx = xnn_loadu_f16(input);
    input += xnn_simd_size_f16;

    // Map the inputs to the interpolation range.
    xnn_simd_f16_t vx_div_2pi = xnn_mul_f16(vx, v2pi_inv);
    vx_div_2pi = xnn_round_f16(vx_div_2pi);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_hi, vx);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_lo, vx);
    vx = xnn_sub_f16(vpi_half, vx);
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));
    vx = xnn_max_f16(vx, xnn_sub_f16(xnn_neg_f16(vpi), vx));
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));

    // Since the polynomials are odd/even, we need x^2.
    const xnn_simd_f16_t vx2 = xnn_mul_f16(vx, vx);

    // Evaluate the numerator polynomial p.
    xnn_simd_f16_t vp = xnn_fmadd_f16(vx2, valpha_3, vone);
    vp = xnn_mul_f16(vx, vp);

    // Evaluate the denominator polynomial q.
    xnn_simd_f16_t vq = xnn_fmadd_f16(vx2, vbeta_2, vone);

    // Divide the numerator by the denominator.
    const xnn_simd_f16_t vy =  xnn_div_f16(vp, vq);

    xnn_storeu_f16(output, vy);
    output += xnn_simd_size_f16;
  }
  if XNN_UNLIKELY(batch != 0) {
    xnn_simd_f16_t vx = xnn_load_tail_f16(input, batch >> XNN_LOG2_SIZEOF_UINT16_T);

    // Map the inputs to the interpolation range.
    xnn_simd_f16_t vx_div_2pi = xnn_mul_f16(vx, v2pi_inv);
    vx_div_2pi = xnn_round_f16(vx_div_2pi);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_hi, vx);
    vx = xnn_fnmadd_f16(vx_div_2pi, v2pi_lo, vx);
    vx = xnn_sub_f16(vpi_half, vx);
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));
    vx = xnn_max_f16(vx, xnn_sub_f16(xnn_neg_f16(vpi), vx));
    vx = xnn_min_f16(vx, xnn_sub_f16(vpi, vx));

    // Since the polynomials are odd/even, we need x^2.
    const xnn_simd_f16_t vx2 = xnn_mul_f16(vx, vx);

    // Evaluate the numerator polynomial p.
    xnn_simd_f16_t vp = xnn_fmadd_f16(vx2, valpha_3, vone);
    vp = xnn_mul_f16(vx, vp);

    // Evaluate the denominator polynomial q.
    xnn_simd_f16_t vq = xnn_fmadd_f16(vx2, vbeta_2, vone);

    // Divide the numerator by the denominator.
    const xnn_simd_f16_t vy =  xnn_div_f16(vp, vq);

    xnn_store_tail_f16(output, vy, batch >> XNN_LOG2_SIZEOF_UINT16_T);
  }
}
