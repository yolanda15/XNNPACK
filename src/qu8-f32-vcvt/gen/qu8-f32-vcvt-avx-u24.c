// Auto-generated file. Do not edit!
//   Template: src/qs8-f32-vcvt/avx.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include "xnnpack/common.h"
#include "xnnpack/unaligned.h"
#include "xnnpack/vcvt.h"


void xnn_qu8_f32_vcvt_ukernel__avx_u24(
    size_t batch,
    const uint8_t* input,
    float* output,
    const union xnn_qu8_f32_cvt_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(uint8_t) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const __m128i vminus_zero_point = _mm_load_si128((const __m128i*) params->avx.minus_zero_point);
  const __m256 vscale = _mm256_load_ps(params->avx.scale);
  for (; batch >= 24 * sizeof(uint8_t); batch -= 24 * sizeof(uint8_t)) {
    __m128i vx0123 = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input)));
    __m128i vx4567 = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input + 4)));
    __m128i vx89AB = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input + 8)));
    __m128i vxCDEF = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input + 12)));
    __m128i vxGHIJ = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input + 16)));
    __m128i vxKLMN = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input + 20)));
    input += 24;

    vx0123 = _mm_add_epi32(vx0123, vminus_zero_point);
    vx4567 = _mm_add_epi32(vx4567, vminus_zero_point);
    vx89AB = _mm_add_epi32(vx89AB, vminus_zero_point);
    vxCDEF = _mm_add_epi32(vxCDEF, vminus_zero_point);
    vxGHIJ = _mm_add_epi32(vxGHIJ, vminus_zero_point);
    vxKLMN = _mm_add_epi32(vxKLMN, vminus_zero_point);

    const __m256i vx01234567 = _mm256_insertf128_si256(_mm256_castsi128_si256(vx0123), vx4567, 1);
    const __m256i vx89ABCDEF = _mm256_insertf128_si256(_mm256_castsi128_si256(vx89AB), vxCDEF, 1);
    const __m256i vxGHIJKLMN = _mm256_insertf128_si256(_mm256_castsi128_si256(vxGHIJ), vxKLMN, 1);

    __m256 vy01234567 = _mm256_cvtepi32_ps(vx01234567);
    __m256 vy89ABCDEF = _mm256_cvtepi32_ps(vx89ABCDEF);
    __m256 vyGHIJKLMN = _mm256_cvtepi32_ps(vxGHIJKLMN);

    vy01234567 = _mm256_mul_ps(vy01234567, vscale);
    vy89ABCDEF = _mm256_mul_ps(vy89ABCDEF, vscale);
    vyGHIJKLMN = _mm256_mul_ps(vyGHIJKLMN, vscale);

    _mm256_storeu_ps(output, vy01234567);
    _mm256_storeu_ps(output + 8, vy89ABCDEF);
    _mm256_storeu_ps(output + 16, vyGHIJKLMN);
    output += 24;
  }
  for (; batch >= 4 * sizeof(uint8_t); batch -= 4 * sizeof(uint8_t)) {
    __m128i vx = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input)));
    vx = _mm_add_epi32(vx, vminus_zero_point);
    input += 4;

    __m128 vy = _mm_cvtepi32_ps(vx);
    vy = _mm_mul_ps(vy, _mm256_castps256_ps128(vscale));

    _mm_storeu_ps(output, vy);
    output += 4;
  }
  if XNN_UNLIKELY(batch != 0) {
    assert(batch >= 1 * sizeof(uint8_t));
    assert(batch <= 3 * sizeof(uint8_t));

    __m128i vx = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input)));
    vx = _mm_add_epi32(vx, vminus_zero_point);

    __m128 vy = _mm_cvtepi32_ps(vx);
    vy = _mm_mul_ps(vy, _mm256_castps256_ps128(vscale));

    if (batch & (2 * sizeof(uint8_t))) {
      _mm_storel_pi((__m64*) output, vy);
      vy = _mm_movehl_ps(vy, vy);
      output += 2;
    }
    if (batch & (1 * sizeof(uint8_t))) {
      _mm_store_ss(output, vy);
    }
  }
}
