// Auto-generated file. Do not edit!
//   Template: src/f32-velu/avx-rr2-p6.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include "xnnpack/common.h"
#include "xnnpack/vunary.h"


void xnn_f32_velu_ukernel__avx_rr2_p6_u16(
    size_t batch,
    const float* input,
    float* output,
    const union xnn_f32_elu_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const __m256 vprescale = _mm256_load_ps(params->avx_rr2_p6.prescale);
  const __m256 valpha = _mm256_load_ps(params->avx_rr2_p6.alpha);
  const __m256 vbeta = _mm256_load_ps(params->avx_rr2_p6.beta);
  const __m256 vsat_cutoff = _mm256_load_ps(params->avx_rr2_p6.sat_cutoff);
  const __m256 vmagic_bias = _mm256_load_ps(params->avx_rr2_p6.magic_bias);
  const __m256 vlog2e = _mm256_load_ps(params->avx_rr2_p6.log2e);
  const __m256 vminus_ln2_hi = _mm256_load_ps(params->avx_rr2_p6.minus_ln2_hi);
  const __m256 vminus_ln2_lo = _mm256_load_ps(params->avx_rr2_p6.minus_ln2_lo);
  const __m256 vc6 = _mm256_load_ps(params->avx_rr2_p6.c6);
  const __m256 vc5 = _mm256_load_ps(params->avx_rr2_p6.c5);
  const __m256 vc4 = _mm256_load_ps(params->avx_rr2_p6.c4);
  const __m256 vc3 = _mm256_load_ps(params->avx_rr2_p6.c3);
  const __m256 vc2 = _mm256_load_ps(params->avx_rr2_p6.c2);
  const __m256 vone = _mm256_load_ps(params->avx_rr2_p6.one);

  for (; batch >= 16 * sizeof(float); batch -= 16 * sizeof(float)) {
    __m256 vx0 = _mm256_loadu_ps(input);
    __m256 vx1 = _mm256_loadu_ps(input + 8);
    input += 16;

    const __m256 vz0 = _mm256_max_ps(vsat_cutoff, _mm256_mul_ps(vx0, vprescale));
    const __m256 vz1 = _mm256_max_ps(vsat_cutoff, _mm256_mul_ps(vx1, vprescale));

    __m256 vn0 = _mm256_add_ps(_mm256_mul_ps(vz0, vlog2e), vmagic_bias);
    __m256 vn1 = _mm256_add_ps(_mm256_mul_ps(vz1, vlog2e), vmagic_bias);

    const __m128 vs0_lo = _mm_castsi128_ps(_mm_slli_epi32(_mm_castps_si128(_mm256_castps256_ps128(vn0)), 23));
    const __m128 vs0_hi = _mm_castsi128_ps(_mm_slli_epi32(_mm_castps_si128(_mm256_extractf128_ps(vn0, 1)), 23));
    vn0 = _mm256_sub_ps(vn0, vmagic_bias);
    const __m128 vs1_lo = _mm_castsi128_ps(_mm_slli_epi32(_mm_castps_si128(_mm256_castps256_ps128(vn1)), 23));
    const __m128 vs1_hi = _mm_castsi128_ps(_mm_slli_epi32(_mm_castps_si128(_mm256_extractf128_ps(vn1, 1)), 23));
    vn1 = _mm256_sub_ps(vn1, vmagic_bias);

    __m256 vt0 = _mm256_add_ps(_mm256_mul_ps(vn0, vminus_ln2_hi), vz0);
    __m256 vs0 = _mm256_insertf128_ps(_mm256_castps128_ps256(vs0_lo), vs0_hi, 1);
    __m256 vt1 = _mm256_add_ps(_mm256_mul_ps(vn1, vminus_ln2_hi), vz1);
    __m256 vs1 = _mm256_insertf128_ps(_mm256_castps128_ps256(vs1_lo), vs1_hi, 1);

    vt0 = _mm256_add_ps(_mm256_mul_ps(vn0, vminus_ln2_lo), vt0);
    vt1 = _mm256_add_ps(_mm256_mul_ps(vn1, vminus_ln2_lo), vt1);

    __m256 vp0 = _mm256_add_ps(_mm256_mul_ps(vc6, vt0), vc5);
    __m256 vp1 = _mm256_add_ps(_mm256_mul_ps(vc6, vt1), vc5);

    vp0 = _mm256_add_ps(_mm256_mul_ps(vp0, vt0), vc4);
    vp1 = _mm256_add_ps(_mm256_mul_ps(vp1, vt1), vc4);

    vp0 = _mm256_add_ps(_mm256_mul_ps(vp0, vt0), vc3);
    vp1 = _mm256_add_ps(_mm256_mul_ps(vp1, vt1), vc3);

    vp0 = _mm256_add_ps(_mm256_mul_ps(vp0, vt0), vc2);
    vp1 = _mm256_add_ps(_mm256_mul_ps(vp1, vt1), vc2);

    vp0 = _mm256_mul_ps(vp0, vt0);
    vp1 = _mm256_mul_ps(vp1, vt1);

    vt0 = _mm256_mul_ps(vt0, vs0);
    vs0 = _mm256_sub_ps(vs0, vone);
    vt1 = _mm256_mul_ps(vt1, vs1);
    vs1 = _mm256_sub_ps(vs1, vone);

    vp0 = _mm256_add_ps(_mm256_mul_ps(vp0, vt0), vt0);
    vp1 = _mm256_add_ps(_mm256_mul_ps(vp1, vt1), vt1);

    const __m256 ve0 = _mm256_mul_ps(_mm256_add_ps(vp0, vs0), valpha);
    vx0 = _mm256_mul_ps(vx0, vbeta);
    const __m256 ve1 = _mm256_mul_ps(_mm256_add_ps(vp1, vs1), valpha);
    vx1 = _mm256_mul_ps(vx1, vbeta);

    const __m256 vy0 = _mm256_blendv_ps(vx0, ve0, vx0);
    const __m256 vy1 = _mm256_blendv_ps(vx1, ve1, vx1);

    _mm256_storeu_ps(output, vy0);
    _mm256_storeu_ps(output + 8, vy1);
    output += 16;
  }
  for (; batch >= 8 * sizeof(float); batch -= 8 * sizeof(float)) {
    __m256 vx = _mm256_loadu_ps(input);
    input += 8;

    const __m256 vz = _mm256_max_ps(vsat_cutoff, _mm256_mul_ps(vx, vprescale));

    __m256 vn = _mm256_add_ps(_mm256_mul_ps(vz, vlog2e), vmagic_bias);
    const __m128 vs_lo = _mm_castsi128_ps(_mm_slli_epi32(_mm_castps_si128(_mm256_castps256_ps128(vn)), 23));
    const __m128 vs_hi = _mm_castsi128_ps(_mm_slli_epi32(_mm_castps_si128(_mm256_extractf128_ps(vn, 1)), 23));
    vn = _mm256_sub_ps(vn, vmagic_bias);

    __m256 vt = _mm256_add_ps(_mm256_mul_ps(vn, vminus_ln2_hi), vz);
    __m256 vs = _mm256_insertf128_ps(_mm256_castps128_ps256(vs_lo), vs_hi, 1);
    vt = _mm256_add_ps(_mm256_mul_ps(vn, vminus_ln2_lo), vt);

    __m256 vp = _mm256_add_ps(_mm256_mul_ps(vc6, vt), vc5);
    vp = _mm256_add_ps(_mm256_mul_ps(vp, vt), vc4);
    vp = _mm256_add_ps(_mm256_mul_ps(vp, vt), vc3);
    vp = _mm256_add_ps(_mm256_mul_ps(vp, vt), vc2);
    vp = _mm256_mul_ps(vp, vt);

    vt = _mm256_mul_ps(vt, vs);
    vs = _mm256_sub_ps(vs, vone);
    vp = _mm256_add_ps(_mm256_mul_ps(vp, vt), vt);

    const __m256 ve = _mm256_mul_ps(_mm256_add_ps(vp, vs), valpha);
    vx = _mm256_mul_ps(vx, vbeta);
    const __m256 vy = _mm256_blendv_ps(vx, ve, vx);

    _mm256_storeu_ps(output, vy);
    output += 8;
  }
  if XNN_UNLIKELY(batch != 0) {
    assert(batch >= 1 * sizeof(float));
    assert(batch <= 7 * sizeof(float));
    const __m256i vmask = _mm256_loadu_si256((const __m256i*) ((uintptr_t) &params->avx_rr2_p6.mask_table[7] - batch));

    __m256 vx = _mm256_maskload_ps(input, vmask);

    const __m256 vz = _mm256_max_ps(vsat_cutoff, _mm256_mul_ps(vx, vprescale));

    __m256 vn = _mm256_add_ps(_mm256_mul_ps(vz, vlog2e), vmagic_bias);
    const __m128 vs_lo = _mm_castsi128_ps(_mm_slli_epi32(_mm_castps_si128(_mm256_castps256_ps128(vn)), 23));
    const __m128 vs_hi = _mm_castsi128_ps(_mm_slli_epi32(_mm_castps_si128(_mm256_extractf128_ps(vn, 1)), 23));
    vn = _mm256_sub_ps(vn, vmagic_bias);

    __m256 vt = _mm256_add_ps(_mm256_mul_ps(vn, vminus_ln2_hi), vz);
    __m256 vs = _mm256_insertf128_ps(_mm256_castps128_ps256(vs_lo), vs_hi, 1);
    vt = _mm256_add_ps(_mm256_mul_ps(vn, vminus_ln2_lo), vt);

    __m256 vp = _mm256_add_ps(_mm256_mul_ps(vc6, vt), vc5);
    vp = _mm256_add_ps(_mm256_mul_ps(vp, vt), vc4);
    vp = _mm256_add_ps(_mm256_mul_ps(vp, vt), vc3);
    vp = _mm256_add_ps(_mm256_mul_ps(vp, vt), vc2);
    vp = _mm256_mul_ps(vp, vt);

    vt = _mm256_mul_ps(vt, vs);
    vs = _mm256_sub_ps(vs, vone);
    vp = _mm256_add_ps(_mm256_mul_ps(vp, vt), vt);

    const __m256 ve = _mm256_mul_ps(_mm256_add_ps(vp, vs), valpha);
    vx = _mm256_mul_ps(vx, vbeta);
    const __m256 vy = _mm256_blendv_ps(vx, ve, vx);

    __m128 vy_lo = _mm256_castps256_ps128(vy);
    if (batch & (4 * sizeof(float))) {
      _mm_storeu_ps(output, vy_lo);
      vy_lo = _mm256_extractf128_ps(vy, 1);
      output += 4;
    }
    if (batch & (2 * sizeof(float))) {
      _mm_storel_pi((__m64*) output, vy_lo);
      vy_lo = _mm_movehl_ps(vy_lo, vy_lo);
      output += 2;
    }
    if (batch & (1 * sizeof(float))) {
      _mm_store_ss(output, vy_lo);
    }
  }
}
