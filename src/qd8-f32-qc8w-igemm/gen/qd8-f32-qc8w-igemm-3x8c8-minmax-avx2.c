// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-igemm/MRx8c8-avx2.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <immintrin.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/igemm.h"
#include "src/xnnpack/intrinsics-polyfill.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/microparams.h"


void xnn_qd8_f32_qc8w_igemm_minmax_ukernel_3x8c8__avx2(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const int8_t** restrict a,
    const void* restrict w,
    float* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const int8_t* zero,
    const int8_t* zero_data,
    const struct xnn_f32_minmax_params* restrict params,
    const struct xnn_qd8_quantization_params* restrict quantization_params) XNN_OOB_READS
{
  assert(mr != 0);
  assert(mr <= 3);
  assert(nc != 0);
  assert(kc != 0);
  assert(ks != 0);
  assert(ks % (3 * sizeof(void*)) == 0);
  assert(a_offset % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 8 * sizeof(int8_t));
  float* c0 = c;
  float* c1 = (float*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    c1 = c0;
  }
  float* c2 = (float*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    c2 = c1;
  }

  const __m256i vinput_zero_point = _mm256_set1_epi32((int) quantization_params->zero_point);
  const __m256 vinput_scale = _mm256_broadcast_ss(&quantization_params->inv_scale);
  const __m256 vmin = _mm256_set1_ps(params->scalar.min);
  const __m256 vmax = _mm256_set1_ps(params->scalar.max);
  // XNN_FORCE_REALIZATION(vinput_zero_point);
  // XNN_FORCE_REALIZATION(vinput_scale);
  // XNN_FORCE_REALIZATION(vmin);
  // XNN_FORCE_REALIZATION(vmax);

  do {
    const __m128i vinit0 = _mm_cvtsi32_si128(((const int*) w)[0]);
    const __m128i vinit1 = _mm_cvtsi32_si128(((const int*) w)[1]);
    const __m256i vinit01 = _mm256_inserti128_si256(_mm256_castsi128_si256(vinit0), vinit1, 1);
    const __m128i vinit2 = _mm_cvtsi32_si128(((const int*) w)[2]);
    const __m128i vinit3 = _mm_cvtsi32_si128(((const int*) w)[3]);
    const __m256i vinit23 = _mm256_inserti128_si256(_mm256_castsi128_si256(vinit2), vinit3, 1);
    const __m128i vinit4 = _mm_cvtsi32_si128(((const int*) w)[4]);
    const __m128i vinit5 = _mm_cvtsi32_si128(((const int*) w)[5]);
    const __m256i vinit45 = _mm256_inserti128_si256(_mm256_castsi128_si256(vinit4), vinit5, 1);
    const __m128i vinit6 = _mm_cvtsi32_si128(((const int*) w)[6]);
    const __m128i vinit7 = _mm_cvtsi32_si128(((const int*) w)[7]);
    const __m256i vinit67 = _mm256_inserti128_si256(_mm256_castsi128_si256(vinit6), vinit7, 1);
    __m256i vacc0x01 = _mm256_mullo_epi32(vinit01, vinput_zero_point);
    __m256i vacc0x23 = _mm256_mullo_epi32(vinit23, vinput_zero_point);
    __m256i vacc0x45 = _mm256_mullo_epi32(vinit45, vinput_zero_point);
    __m256i vacc0x67 = _mm256_mullo_epi32(vinit67, vinput_zero_point);
    __m256i vacc1x01 = vacc0x01;
    __m256i vacc1x23 = vacc0x23;
    __m256i vacc1x45 = vacc0x45;
    __m256i vacc1x67 = vacc0x67;
    __m256i vacc2x01 = vacc0x01;
    __m256i vacc2x23 = vacc0x23;
    __m256i vacc2x45 = vacc0x45;
    __m256i vacc2x67 = vacc0x67;
    w = (const int32_t*) w + 8;

    size_t p = ks;
    do {
      const int8_t* restrict a0 = a[0];
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const int8_t*) ((uintptr_t) a0 + a_offset);
      } else {
        a0 = zero_data;
      }
      const int8_t* restrict a1 = a[1];
      if XNN_UNPREDICTABLE(a1 != zero) {
        a1 = (const int8_t*) ((uintptr_t) a1 + a_offset);
      } else {
        a1 = zero_data;
      }
      const int8_t* restrict a2 = a[2];
      if XNN_UNPREDICTABLE(a2 != zero) {
        a2 = (const int8_t*) ((uintptr_t) a2 + a_offset);
      } else {
        a2 = zero_data;
      }
      a += 3;

      size_t k = 0;
      while (k < kc) {
        const __m128i va0 = _mm_broadcastq_epi64(_mm_loadl_epi64((const __m128i*) a0));
        const __m256i vxa0 = _mm256_cvtepi8_epi16(va0);
        a0 += 8;
        const __m128i va1 = _mm_broadcastq_epi64(_mm_loadl_epi64((const __m128i*) a1));
        const __m256i vxa1 = _mm256_cvtepi8_epi16(va1);
        a1 += 8;
        const __m128i va2 = _mm_broadcastq_epi64(_mm_loadl_epi64((const __m128i*) a2));
        const __m256i vxa2 = _mm256_cvtepi8_epi16(va2);
        a2 += 8;

        const __m128i vb01 = _mm_load_si128((const __m128i*) w);
        const __m256i vxb01 = _mm256_cvtepi8_epi16(vb01);

        vacc0x01 = _mm256_add_epi32(vacc0x01, _mm256_madd_epi16(vxa0, vxb01));
        vacc1x01 = _mm256_add_epi32(vacc1x01, _mm256_madd_epi16(vxa1, vxb01));
        vacc2x01 = _mm256_add_epi32(vacc2x01, _mm256_madd_epi16(vxa2, vxb01));
        const __m128i vb23 = _mm_load_si128((const __m128i*) ((const int8_t*) w + 16));
        const __m256i vxb23 = _mm256_cvtepi8_epi16(vb23);

        vacc0x23 = _mm256_add_epi32(vacc0x23, _mm256_madd_epi16(vxa0, vxb23));
        vacc1x23 = _mm256_add_epi32(vacc1x23, _mm256_madd_epi16(vxa1, vxb23));
        vacc2x23 = _mm256_add_epi32(vacc2x23, _mm256_madd_epi16(vxa2, vxb23));
        const __m128i vb45 = _mm_load_si128((const __m128i*) ((const int8_t*) w + 32));
        const __m256i vxb45 = _mm256_cvtepi8_epi16(vb45);

        vacc0x45 = _mm256_add_epi32(vacc0x45, _mm256_madd_epi16(vxa0, vxb45));
        vacc1x45 = _mm256_add_epi32(vacc1x45, _mm256_madd_epi16(vxa1, vxb45));
        vacc2x45 = _mm256_add_epi32(vacc2x45, _mm256_madd_epi16(vxa2, vxb45));
        const __m128i vb67 = _mm_load_si128((const __m128i*) ((const int8_t*) w + 48));
        const __m256i vxb67 = _mm256_cvtepi8_epi16(vb67);

        vacc0x67 = _mm256_add_epi32(vacc0x67, _mm256_madd_epi16(vxa0, vxb67));
        vacc1x67 = _mm256_add_epi32(vacc1x67, _mm256_madd_epi16(vxa1, vxb67));
        vacc2x67 = _mm256_add_epi32(vacc2x67, _mm256_madd_epi16(vxa2, vxb67));

        w = (const void*) ((const int8_t*) w + 64);
        k += 8 * sizeof(int8_t);
      }
      p -= 3 * sizeof(void*);
    } while (p != 0);

    const __m256i vacc0x0213 = _mm256_hadd_epi32(vacc0x01, vacc0x23);
    const __m256i vacc0x4657 = _mm256_hadd_epi32(vacc0x45, vacc0x67);
    const __m256i vacc1x0213 = _mm256_hadd_epi32(vacc1x01, vacc1x23);
    const __m256i vacc1x4657 = _mm256_hadd_epi32(vacc1x45, vacc1x67);
    const __m256i vacc2x0213 = _mm256_hadd_epi32(vacc2x01, vacc2x23);
    const __m256i vacc2x4657 = _mm256_hadd_epi32(vacc2x45, vacc2x67);

    const __m256i vacc0x02461357 = _mm256_hadd_epi32(vacc0x0213, vacc0x4657);
    const __m256i vacc1x02461357 = _mm256_hadd_epi32(vacc1x0213, vacc1x4657);
    const __m256i vacc2x02461357 = _mm256_hadd_epi32(vacc2x0213, vacc2x4657);

    const __m256i vpermute_mask = _mm256_set_epi32(7, 3, 6, 2, 5, 1, 4, 0);
    __m256i vacc0x01234567 = _mm256_permutevar8x32_epi32(vacc0x02461357, vpermute_mask);
    __m256i vacc1x01234567 = _mm256_permutevar8x32_epi32(vacc1x02461357, vpermute_mask);
    __m256i vacc2x01234567 = _mm256_permutevar8x32_epi32(vacc2x02461357, vpermute_mask);

    __m256 vout0x01234567 = _mm256_cvtepi32_ps(vacc0x01234567);
    __m256 vout1x01234567 = _mm256_cvtepi32_ps(vacc1x01234567);
    __m256 vout2x01234567 = _mm256_cvtepi32_ps(vacc2x01234567);

    vout0x01234567 = _mm256_mul_ps(vout0x01234567, vinput_scale);
    vout1x01234567 = _mm256_mul_ps(vout1x01234567, vinput_scale);
    vout2x01234567 = _mm256_mul_ps(vout2x01234567, vinput_scale);

    const __m256 vfilter_output_scale01234567 = _mm256_load_ps((const float*) w);
    const __m256 vbias01234567 = _mm256_load_ps((const float*) w + 8);
    w = (const float*) w + 16;
    vout0x01234567 = _mm256_fmadd_ps(vout0x01234567, vfilter_output_scale01234567, vbias01234567);
    vout1x01234567 = _mm256_fmadd_ps(vout1x01234567, vfilter_output_scale01234567, vbias01234567);
    vout2x01234567 = _mm256_fmadd_ps(vout2x01234567, vfilter_output_scale01234567, vbias01234567);

    vout0x01234567 = _mm256_max_ps(vout0x01234567, vmin);
    vout1x01234567 = _mm256_max_ps(vout1x01234567, vmin);
    vout2x01234567 = _mm256_max_ps(vout2x01234567, vmin);

    vout0x01234567 = _mm256_min_ps(vout0x01234567, vmax);
    vout1x01234567 = _mm256_min_ps(vout1x01234567, vmax);
    vout2x01234567 = _mm256_min_ps(vout2x01234567, vmax);

    if XNN_LIKELY(nc >= 8) {
      _mm256_storeu_ps(c2, vout2x01234567);
      c2 = (float*) ((uintptr_t) c2 + cn_stride);
      _mm256_storeu_ps(c1, vout1x01234567);
      c1 = (float*) ((uintptr_t) c1 + cn_stride);
      _mm256_storeu_ps(c0, vout0x01234567);
      c0 = (float*) ((uintptr_t) c0 + cn_stride);

      a = (const int8_t**restrict) ((uintptr_t) a - ks);
      nc -= 8;
    } else {
      __m128 vout2x0123 = _mm256_castps256_ps128(vout2x01234567);
      __m128 vout1x0123 = _mm256_castps256_ps128(vout1x01234567);
      __m128 vout0x0123 = _mm256_castps256_ps128(vout0x01234567);
      if (nc & 4) {
        _mm_storeu_ps(c2, vout2x0123);
        _mm_storeu_ps(c1, vout1x0123);
        _mm_storeu_ps(c0, vout0x0123);

        vout2x0123 = _mm256_extractf128_ps(vout2x01234567, 1);
        vout1x0123 = _mm256_extractf128_ps(vout1x01234567, 1);
        vout0x0123 = _mm256_extractf128_ps(vout0x01234567, 1);

        c2 += 4;
        c1 += 4;
        c0 += 4;
      }
      if (nc & 2) {
        _mm_storel_pi((__m64*) c2, vout2x0123);
        _mm_storel_pi((__m64*) c1, vout1x0123);
        _mm_storel_pi((__m64*) c0, vout0x0123);

        vout2x0123 = _mm_movehl_ps(vout2x0123, vout2x0123);
        vout1x0123 = _mm_movehl_ps(vout1x0123, vout1x0123);
        vout0x0123 = _mm_movehl_ps(vout0x0123, vout0x0123);

        c2 += 2;
        c1 += 2;
        c0 += 2;
      }
      if (nc & 1) {
        _mm_store_ss(c2, vout2x0123);
        _mm_store_ss(c1, vout1x0123);
        _mm_store_ss(c0, vout0x0123);
      }
      nc = 0;
    }
  } while (nc != 0);
}
