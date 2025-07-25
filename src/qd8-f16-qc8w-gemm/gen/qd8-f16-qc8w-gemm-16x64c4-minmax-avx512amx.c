// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/c4-avx512amx.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#if defined(__has_feature)
  #if __has_feature(memory_sanitizer)
    #include <sanitizer/msan_interface.h>
  #endif
#endif

#include <immintrin.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/gemm.h"
#include "src/xnnpack/intrinsics-polyfill.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/microparams.h"


void xnn_qd8_f16_qc8w_gemm_minmax_ukernel_16x64c4__avx512amx(
    size_t mr,
    size_t nc,
    size_t kc,
    const int8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    xnn_float16* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const struct xnn_f16_minmax_params* restrict params,
    const struct xnn_qd8_quantization_params* restrict quantization_params)
{
  assert(mr != 0);
  assert(mr <= 16);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

// AMX is only available for __x86_64__
#if XNN_ARCH_X86_64

  // Define tile config data structure
  struct __tile_config {
    uint8_t palette_id;
    uint8_t start_row;
    uint8_t reserved_0[14];
    uint16_t colsb[8];
    uint16_t reserved_1[8];
    uint8_t rows[8];
    uint8_t reserved_2[8];
  };

  XNN_ALIGN(64) struct __tile_config tile_data = {0};
  XNN_ALIGN(64) int32_t res[4][16 * 16];

  kc = round_up_po2(kc, 4 * sizeof(int8_t));
  const size_t kremainder = (kc & 63) ? (kc & 63) : 64;

  tile_data.palette_id = 1;
  tile_data.rows[0] = mr;              // tmm0 = res[0]
  tile_data.rows[1] = mr;              // tmm1 = res[1]
  tile_data.rows[2] = mr;              // tmm2 = res[2]
  tile_data.rows[3] = mr;              // tmm3 = res[3]
  tile_data.rows[4] = mr;              // tmm4 = input
  tile_data.rows[5] = 16;              // tmm5 = weights
  tile_data.rows[6] = mr;              // tmm6 = input remainder
  tile_data.rows[7] = kremainder >> 2; // tmm7 = weights remainder
  tile_data.colsb[0] = 64;          // tmm0 = res[0]
  tile_data.colsb[1] = 64;          // tmm1 = res[1]
  tile_data.colsb[2] = 64;          // tmm2 = res[2]
  tile_data.colsb[3] = 64;          // tmm3 = res[3]
  tile_data.colsb[4] = 64;          // tmm4 = input
  tile_data.colsb[5] = 64;          // tmm5 = weights
  tile_data.colsb[6] = kremainder;  // tmm6 = input remainder
  tile_data.colsb[7] = 64;          // tmm7 = weights remainder
  _tile_loadconfig(&tile_data);

  xnn_float16* c0 = c;
  xnn_float16* c1 = (xnn_float16*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    c1 = c0;
  }
  xnn_float16* c2 = (xnn_float16*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    c2 = c1;
  }
  xnn_float16* c3 = (xnn_float16*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 4) {
    c3 = c2;
  }
  xnn_float16* c4 = (xnn_float16*) ((uintptr_t) c3 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 4) {
    c4 = c3;
  }
  xnn_float16* c5 = (xnn_float16*) ((uintptr_t) c4 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 6) {
    c5 = c4;
  }
  xnn_float16* c6 = (xnn_float16*) ((uintptr_t) c5 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 6) {
    c6 = c5;
  }
  xnn_float16* c7 = (xnn_float16*) ((uintptr_t) c6 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 8) {
    c7 = c6;
  }
  xnn_float16* c8 = (xnn_float16*) ((uintptr_t) c7 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 8) {
    c8 = c7;
  }
  xnn_float16* c9 = (xnn_float16*) ((uintptr_t) c8 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 10) {
    c9 = c8;
  }
  xnn_float16* c10 = (xnn_float16*) ((uintptr_t) c9 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 10) {
    c10 = c9;
  }
  xnn_float16* c11 = (xnn_float16*) ((uintptr_t) c10 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 12) {
    c11 = c10;
  }
  xnn_float16* c12 = (xnn_float16*) ((uintptr_t) c11 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 12) {
    c12 = c11;
  }
  xnn_float16* c13 = (xnn_float16*) ((uintptr_t) c12 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 14) {
    c13 = c12;
  }
  xnn_float16* c14 = (xnn_float16*) ((uintptr_t) c13 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 14) {
    c14 = c13;
  }
  xnn_float16* c15 = (xnn_float16*) ((uintptr_t) c14 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 16) {
    c15 = c14;
  }

  const __m512 voutput_min = _mm512_cvtph_ps(_mm256_set1_epi16(*(const uint16_t*) &params->scalar.min));
  const __m512 voutput_max = _mm512_cvtph_ps(_mm256_set1_epi16(*(const uint16_t*) &params->scalar.max));
  // XNN_FORCE_REALIZATION(voutput_min);
  // XNN_FORCE_REALIZATION(voutput_max);

  do {
    const __m512i vksum0123456789ABCDEF = _mm512_load_epi32((const int32_t*) w + 0);
    const __m512i vksumGHIJKLMNOPQRSTUV = _mm512_load_epi32((const int32_t*) w + 16);
    const __m512i vksumWXYZabcdefghijkl = _mm512_load_epi32((const int32_t*) w + 32);
    const __m512i vksummnopqrstuvwxyz01 = _mm512_load_epi32((const int32_t*) w + 48);
    w = (const int32_t*) w + 64;

    // Zero tile accumulator
    _tile_zero(0);
    _tile_zero(1);
    _tile_zero(2);
    _tile_zero(3);

    size_t k = kc;
    while (k >= 64 * sizeof(int8_t)) {
      _tile_loadd(4, a, a_stride);
      a += 64;
      _tile_loadd(5, (const int8_t*) w + 0, 256);
      _tile_dpbssd(0, 4, 5);
      _tile_loadd(5, (const int8_t*) w + 64, 256);
      _tile_dpbssd(1, 4, 5);
      _tile_loadd(5, (const int8_t*) w + 128, 256);
      _tile_dpbssd(2, 4, 5);
      _tile_loadd(5, (const int8_t*) w + 192, 256);
      _tile_dpbssd(3, 4, 5);

      w = (const int8_t*) w + 4096;
      k -= 64 * sizeof(int8_t);
    }

    if XNN_UNLIKELY(k != 0) {
      _tile_loadd(6, a, a_stride);
      a += kremainder;
      _tile_loadd(7, (const int8_t*) w + 0, 256);
      _tile_dpbssd(0, 6, 7);
      _tile_loadd(7, (const int8_t*) w + 64, 256);
      _tile_dpbssd(1, 6, 7);
      _tile_loadd(7, (const int8_t*) w + 128, 256);
      _tile_dpbssd(2, 6, 7);
      _tile_loadd(7, (const int8_t*) w + 192, 256);
      _tile_dpbssd(3, 6, 7);

      w = (const int8_t*) w + kremainder * 64;
      k -= kremainder * sizeof(int8_t);
    }

    // TODO: Instead of processing up to 4 tiles (16x64) consider
    // quantizing 1 tile at a time (16 registers)
    _tile_stored(0, &res[0][0], 64);
    _tile_stored(1, &res[1][0], 64);
    _tile_stored(2, &res[2][0], 64);
    _tile_stored(3, &res[3][0], 64);

    // TODO: Fix msan for AMX
    #if defined(__has_feature)
      #if __has_feature(memory_sanitizer)
        __msan_unpoison(res, sizeof(res));
      #endif
    #endif

    // TODO: Instead of processing up to 4 tiles (16x64) consider
    // quantizing 1 row at a time.
    __m512i vacc0x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[0].zero_point));
    __m512i vacc0xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[0].zero_point));
    __m512i vacc0xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[0].zero_point));
    __m512i vacc0xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[0].zero_point));
    __m512i vacc1x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[1].zero_point));
    __m512i vacc1xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[1].zero_point));
    __m512i vacc1xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[1].zero_point));
    __m512i vacc1xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[1].zero_point));
    __m512i vacc2x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[2].zero_point));
    __m512i vacc2xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[2].zero_point));
    __m512i vacc2xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[2].zero_point));
    __m512i vacc2xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[2].zero_point));
    __m512i vacc3x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[3].zero_point));
    __m512i vacc3xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[3].zero_point));
    __m512i vacc3xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[3].zero_point));
    __m512i vacc3xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[3].zero_point));
    __m512i vacc4x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[4].zero_point));
    __m512i vacc4xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[4].zero_point));
    __m512i vacc4xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[4].zero_point));
    __m512i vacc4xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[4].zero_point));
    __m512i vacc5x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[5].zero_point));
    __m512i vacc5xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[5].zero_point));
    __m512i vacc5xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[5].zero_point));
    __m512i vacc5xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[5].zero_point));
    __m512i vacc6x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[6].zero_point));
    __m512i vacc6xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[6].zero_point));
    __m512i vacc6xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[6].zero_point));
    __m512i vacc6xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[6].zero_point));
    __m512i vacc7x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[7].zero_point));
    __m512i vacc7xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[7].zero_point));
    __m512i vacc7xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[7].zero_point));
    __m512i vacc7xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[7].zero_point));
    __m512i vacc8x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[8].zero_point));
    __m512i vacc8xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[8].zero_point));
    __m512i vacc8xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[8].zero_point));
    __m512i vacc8xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[8].zero_point));
    __m512i vacc9x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[9].zero_point));
    __m512i vacc9xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[9].zero_point));
    __m512i vacc9xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[9].zero_point));
    __m512i vacc9xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[9].zero_point));
    __m512i vacc10x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[10].zero_point));
    __m512i vacc10xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[10].zero_point));
    __m512i vacc10xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[10].zero_point));
    __m512i vacc10xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[10].zero_point));
    __m512i vacc11x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[11].zero_point));
    __m512i vacc11xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[11].zero_point));
    __m512i vacc11xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[11].zero_point));
    __m512i vacc11xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[11].zero_point));
    __m512i vacc12x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[12].zero_point));
    __m512i vacc12xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[12].zero_point));
    __m512i vacc12xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[12].zero_point));
    __m512i vacc12xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[12].zero_point));
    __m512i vacc13x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[13].zero_point));
    __m512i vacc13xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[13].zero_point));
    __m512i vacc13xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[13].zero_point));
    __m512i vacc13xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[13].zero_point));
    __m512i vacc14x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[14].zero_point));
    __m512i vacc14xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[14].zero_point));
    __m512i vacc14xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[14].zero_point));
    __m512i vacc14xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[14].zero_point));
    __m512i vacc15x0123456789ABCDEF = _mm512_mullo_epi32(vksum0123456789ABCDEF, _mm512_set1_epi32((int) quantization_params[15].zero_point));
    __m512i vacc15xGHIJKLMNOPQRSTUV = _mm512_mullo_epi32(vksumGHIJKLMNOPQRSTUV, _mm512_set1_epi32((int) quantization_params[15].zero_point));
    __m512i vacc15xWXYZabcdefghijkl = _mm512_mullo_epi32(vksumWXYZabcdefghijkl, _mm512_set1_epi32((int) quantization_params[15].zero_point));
    __m512i vacc15xmnopqrstuvwxyz01 = _mm512_mullo_epi32(vksummnopqrstuvwxyz01, _mm512_set1_epi32((int) quantization_params[15].zero_point));
    // Add tile to bias
    vacc0x0123456789ABCDEF = _mm512_add_epi32(vacc0x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 0));
    vacc0xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc0xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 0));
    vacc0xWXYZabcdefghijkl = _mm512_add_epi32(vacc0xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 0));
    vacc0xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc0xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 0));
    vacc1x0123456789ABCDEF = _mm512_add_epi32(vacc1x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 16));
    vacc1xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc1xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 16));
    vacc1xWXYZabcdefghijkl = _mm512_add_epi32(vacc1xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 16));
    vacc1xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc1xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 16));
    vacc2x0123456789ABCDEF = _mm512_add_epi32(vacc2x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 32));
    vacc2xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc2xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 32));
    vacc2xWXYZabcdefghijkl = _mm512_add_epi32(vacc2xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 32));
    vacc2xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc2xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 32));
    vacc3x0123456789ABCDEF = _mm512_add_epi32(vacc3x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 48));
    vacc3xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc3xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 48));
    vacc3xWXYZabcdefghijkl = _mm512_add_epi32(vacc3xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 48));
    vacc3xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc3xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 48));
    vacc4x0123456789ABCDEF = _mm512_add_epi32(vacc4x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 64));
    vacc4xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc4xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 64));
    vacc4xWXYZabcdefghijkl = _mm512_add_epi32(vacc4xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 64));
    vacc4xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc4xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 64));
    vacc5x0123456789ABCDEF = _mm512_add_epi32(vacc5x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 80));
    vacc5xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc5xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 80));
    vacc5xWXYZabcdefghijkl = _mm512_add_epi32(vacc5xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 80));
    vacc5xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc5xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 80));
    vacc6x0123456789ABCDEF = _mm512_add_epi32(vacc6x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 96));
    vacc6xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc6xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 96));
    vacc6xWXYZabcdefghijkl = _mm512_add_epi32(vacc6xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 96));
    vacc6xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc6xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 96));
    vacc7x0123456789ABCDEF = _mm512_add_epi32(vacc7x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 112));
    vacc7xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc7xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 112));
    vacc7xWXYZabcdefghijkl = _mm512_add_epi32(vacc7xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 112));
    vacc7xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc7xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 112));
    vacc8x0123456789ABCDEF = _mm512_add_epi32(vacc8x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 128));
    vacc8xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc8xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 128));
    vacc8xWXYZabcdefghijkl = _mm512_add_epi32(vacc8xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 128));
    vacc8xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc8xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 128));
    vacc9x0123456789ABCDEF = _mm512_add_epi32(vacc9x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 144));
    vacc9xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc9xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 144));
    vacc9xWXYZabcdefghijkl = _mm512_add_epi32(vacc9xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 144));
    vacc9xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc9xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 144));
    vacc10x0123456789ABCDEF = _mm512_add_epi32(vacc10x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 160));
    vacc10xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc10xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 160));
    vacc10xWXYZabcdefghijkl = _mm512_add_epi32(vacc10xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 160));
    vacc10xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc10xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 160));
    vacc11x0123456789ABCDEF = _mm512_add_epi32(vacc11x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 176));
    vacc11xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc11xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 176));
    vacc11xWXYZabcdefghijkl = _mm512_add_epi32(vacc11xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 176));
    vacc11xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc11xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 176));
    vacc12x0123456789ABCDEF = _mm512_add_epi32(vacc12x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 192));
    vacc12xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc12xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 192));
    vacc12xWXYZabcdefghijkl = _mm512_add_epi32(vacc12xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 192));
    vacc12xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc12xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 192));
    vacc13x0123456789ABCDEF = _mm512_add_epi32(vacc13x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 208));
    vacc13xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc13xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 208));
    vacc13xWXYZabcdefghijkl = _mm512_add_epi32(vacc13xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 208));
    vacc13xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc13xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 208));
    vacc14x0123456789ABCDEF = _mm512_add_epi32(vacc14x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 224));
    vacc14xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc14xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 224));
    vacc14xWXYZabcdefghijkl = _mm512_add_epi32(vacc14xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 224));
    vacc14xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc14xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 224));
    vacc15x0123456789ABCDEF = _mm512_add_epi32(vacc15x0123456789ABCDEF, _mm512_load_epi32(&res[0][0] + 240));
    vacc15xGHIJKLMNOPQRSTUV = _mm512_add_epi32(vacc15xGHIJKLMNOPQRSTUV, _mm512_load_epi32(&res[1][0] + 240));
    vacc15xWXYZabcdefghijkl = _mm512_add_epi32(vacc15xWXYZabcdefghijkl, _mm512_load_epi32(&res[2][0] + 240));
    vacc15xmnopqrstuvwxyz01 = _mm512_add_epi32(vacc15xmnopqrstuvwxyz01, _mm512_load_epi32(&res[3][0] + 240));

    __m512 vscaled0x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc0x0123456789ABCDEF);
    __m512 vscaled0xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc0xGHIJKLMNOPQRSTUV);
    __m512 vscaled0xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc0xWXYZabcdefghijkl);
    __m512 vscaled0xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc0xmnopqrstuvwxyz01);
    __m512 vscaled1x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc1x0123456789ABCDEF);
    __m512 vscaled1xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc1xGHIJKLMNOPQRSTUV);
    __m512 vscaled1xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc1xWXYZabcdefghijkl);
    __m512 vscaled1xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc1xmnopqrstuvwxyz01);
    __m512 vscaled2x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc2x0123456789ABCDEF);
    __m512 vscaled2xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc2xGHIJKLMNOPQRSTUV);
    __m512 vscaled2xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc2xWXYZabcdefghijkl);
    __m512 vscaled2xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc2xmnopqrstuvwxyz01);
    __m512 vscaled3x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc3x0123456789ABCDEF);
    __m512 vscaled3xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc3xGHIJKLMNOPQRSTUV);
    __m512 vscaled3xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc3xWXYZabcdefghijkl);
    __m512 vscaled3xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc3xmnopqrstuvwxyz01);
    __m512 vscaled4x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc4x0123456789ABCDEF);
    __m512 vscaled4xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc4xGHIJKLMNOPQRSTUV);
    __m512 vscaled4xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc4xWXYZabcdefghijkl);
    __m512 vscaled4xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc4xmnopqrstuvwxyz01);
    __m512 vscaled5x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc5x0123456789ABCDEF);
    __m512 vscaled5xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc5xGHIJKLMNOPQRSTUV);
    __m512 vscaled5xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc5xWXYZabcdefghijkl);
    __m512 vscaled5xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc5xmnopqrstuvwxyz01);
    __m512 vscaled6x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc6x0123456789ABCDEF);
    __m512 vscaled6xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc6xGHIJKLMNOPQRSTUV);
    __m512 vscaled6xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc6xWXYZabcdefghijkl);
    __m512 vscaled6xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc6xmnopqrstuvwxyz01);
    __m512 vscaled7x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc7x0123456789ABCDEF);
    __m512 vscaled7xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc7xGHIJKLMNOPQRSTUV);
    __m512 vscaled7xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc7xWXYZabcdefghijkl);
    __m512 vscaled7xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc7xmnopqrstuvwxyz01);
    __m512 vscaled8x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc8x0123456789ABCDEF);
    __m512 vscaled8xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc8xGHIJKLMNOPQRSTUV);
    __m512 vscaled8xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc8xWXYZabcdefghijkl);
    __m512 vscaled8xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc8xmnopqrstuvwxyz01);
    __m512 vscaled9x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc9x0123456789ABCDEF);
    __m512 vscaled9xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc9xGHIJKLMNOPQRSTUV);
    __m512 vscaled9xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc9xWXYZabcdefghijkl);
    __m512 vscaled9xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc9xmnopqrstuvwxyz01);
    __m512 vscaled10x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc10x0123456789ABCDEF);
    __m512 vscaled10xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc10xGHIJKLMNOPQRSTUV);
    __m512 vscaled10xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc10xWXYZabcdefghijkl);
    __m512 vscaled10xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc10xmnopqrstuvwxyz01);
    __m512 vscaled11x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc11x0123456789ABCDEF);
    __m512 vscaled11xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc11xGHIJKLMNOPQRSTUV);
    __m512 vscaled11xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc11xWXYZabcdefghijkl);
    __m512 vscaled11xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc11xmnopqrstuvwxyz01);
    __m512 vscaled12x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc12x0123456789ABCDEF);
    __m512 vscaled12xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc12xGHIJKLMNOPQRSTUV);
    __m512 vscaled12xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc12xWXYZabcdefghijkl);
    __m512 vscaled12xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc12xmnopqrstuvwxyz01);
    __m512 vscaled13x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc13x0123456789ABCDEF);
    __m512 vscaled13xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc13xGHIJKLMNOPQRSTUV);
    __m512 vscaled13xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc13xWXYZabcdefghijkl);
    __m512 vscaled13xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc13xmnopqrstuvwxyz01);
    __m512 vscaled14x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc14x0123456789ABCDEF);
    __m512 vscaled14xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc14xGHIJKLMNOPQRSTUV);
    __m512 vscaled14xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc14xWXYZabcdefghijkl);
    __m512 vscaled14xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc14xmnopqrstuvwxyz01);
    __m512 vscaled15x0123456789ABCDEF = _mm512_cvtepi32_ps(vacc15x0123456789ABCDEF);
    __m512 vscaled15xGHIJKLMNOPQRSTUV = _mm512_cvtepi32_ps(vacc15xGHIJKLMNOPQRSTUV);
    __m512 vscaled15xWXYZabcdefghijkl = _mm512_cvtepi32_ps(vacc15xWXYZabcdefghijkl);
    __m512 vscaled15xmnopqrstuvwxyz01 = _mm512_cvtepi32_ps(vacc15xmnopqrstuvwxyz01);

    vscaled0x0123456789ABCDEF = _mm512_mul_ps(vscaled0x0123456789ABCDEF, _mm512_set1_ps(quantization_params[0].inv_scale));
    vscaled0xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled0xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[0].inv_scale));
    vscaled0xWXYZabcdefghijkl = _mm512_mul_ps(vscaled0xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[0].inv_scale));
    vscaled0xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled0xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[0].inv_scale));
    vscaled1x0123456789ABCDEF = _mm512_mul_ps(vscaled1x0123456789ABCDEF, _mm512_set1_ps(quantization_params[1].inv_scale));
    vscaled1xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled1xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[1].inv_scale));
    vscaled1xWXYZabcdefghijkl = _mm512_mul_ps(vscaled1xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[1].inv_scale));
    vscaled1xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled1xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[1].inv_scale));
    vscaled2x0123456789ABCDEF = _mm512_mul_ps(vscaled2x0123456789ABCDEF, _mm512_set1_ps(quantization_params[2].inv_scale));
    vscaled2xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled2xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[2].inv_scale));
    vscaled2xWXYZabcdefghijkl = _mm512_mul_ps(vscaled2xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[2].inv_scale));
    vscaled2xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled2xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[2].inv_scale));
    vscaled3x0123456789ABCDEF = _mm512_mul_ps(vscaled3x0123456789ABCDEF, _mm512_set1_ps(quantization_params[3].inv_scale));
    vscaled3xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled3xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[3].inv_scale));
    vscaled3xWXYZabcdefghijkl = _mm512_mul_ps(vscaled3xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[3].inv_scale));
    vscaled3xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled3xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[3].inv_scale));
    vscaled4x0123456789ABCDEF = _mm512_mul_ps(vscaled4x0123456789ABCDEF, _mm512_set1_ps(quantization_params[4].inv_scale));
    vscaled4xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled4xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[4].inv_scale));
    vscaled4xWXYZabcdefghijkl = _mm512_mul_ps(vscaled4xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[4].inv_scale));
    vscaled4xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled4xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[4].inv_scale));
    vscaled5x0123456789ABCDEF = _mm512_mul_ps(vscaled5x0123456789ABCDEF, _mm512_set1_ps(quantization_params[5].inv_scale));
    vscaled5xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled5xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[5].inv_scale));
    vscaled5xWXYZabcdefghijkl = _mm512_mul_ps(vscaled5xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[5].inv_scale));
    vscaled5xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled5xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[5].inv_scale));
    vscaled6x0123456789ABCDEF = _mm512_mul_ps(vscaled6x0123456789ABCDEF, _mm512_set1_ps(quantization_params[6].inv_scale));
    vscaled6xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled6xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[6].inv_scale));
    vscaled6xWXYZabcdefghijkl = _mm512_mul_ps(vscaled6xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[6].inv_scale));
    vscaled6xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled6xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[6].inv_scale));
    vscaled7x0123456789ABCDEF = _mm512_mul_ps(vscaled7x0123456789ABCDEF, _mm512_set1_ps(quantization_params[7].inv_scale));
    vscaled7xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled7xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[7].inv_scale));
    vscaled7xWXYZabcdefghijkl = _mm512_mul_ps(vscaled7xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[7].inv_scale));
    vscaled7xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled7xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[7].inv_scale));
    vscaled8x0123456789ABCDEF = _mm512_mul_ps(vscaled8x0123456789ABCDEF, _mm512_set1_ps(quantization_params[8].inv_scale));
    vscaled8xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled8xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[8].inv_scale));
    vscaled8xWXYZabcdefghijkl = _mm512_mul_ps(vscaled8xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[8].inv_scale));
    vscaled8xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled8xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[8].inv_scale));
    vscaled9x0123456789ABCDEF = _mm512_mul_ps(vscaled9x0123456789ABCDEF, _mm512_set1_ps(quantization_params[9].inv_scale));
    vscaled9xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled9xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[9].inv_scale));
    vscaled9xWXYZabcdefghijkl = _mm512_mul_ps(vscaled9xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[9].inv_scale));
    vscaled9xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled9xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[9].inv_scale));
    vscaled10x0123456789ABCDEF = _mm512_mul_ps(vscaled10x0123456789ABCDEF, _mm512_set1_ps(quantization_params[10].inv_scale));
    vscaled10xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled10xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[10].inv_scale));
    vscaled10xWXYZabcdefghijkl = _mm512_mul_ps(vscaled10xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[10].inv_scale));
    vscaled10xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled10xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[10].inv_scale));
    vscaled11x0123456789ABCDEF = _mm512_mul_ps(vscaled11x0123456789ABCDEF, _mm512_set1_ps(quantization_params[11].inv_scale));
    vscaled11xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled11xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[11].inv_scale));
    vscaled11xWXYZabcdefghijkl = _mm512_mul_ps(vscaled11xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[11].inv_scale));
    vscaled11xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled11xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[11].inv_scale));
    vscaled12x0123456789ABCDEF = _mm512_mul_ps(vscaled12x0123456789ABCDEF, _mm512_set1_ps(quantization_params[12].inv_scale));
    vscaled12xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled12xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[12].inv_scale));
    vscaled12xWXYZabcdefghijkl = _mm512_mul_ps(vscaled12xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[12].inv_scale));
    vscaled12xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled12xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[12].inv_scale));
    vscaled13x0123456789ABCDEF = _mm512_mul_ps(vscaled13x0123456789ABCDEF, _mm512_set1_ps(quantization_params[13].inv_scale));
    vscaled13xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled13xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[13].inv_scale));
    vscaled13xWXYZabcdefghijkl = _mm512_mul_ps(vscaled13xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[13].inv_scale));
    vscaled13xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled13xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[13].inv_scale));
    vscaled14x0123456789ABCDEF = _mm512_mul_ps(vscaled14x0123456789ABCDEF, _mm512_set1_ps(quantization_params[14].inv_scale));
    vscaled14xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled14xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[14].inv_scale));
    vscaled14xWXYZabcdefghijkl = _mm512_mul_ps(vscaled14xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[14].inv_scale));
    vscaled14xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled14xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[14].inv_scale));
    vscaled15x0123456789ABCDEF = _mm512_mul_ps(vscaled15x0123456789ABCDEF, _mm512_set1_ps(quantization_params[15].inv_scale));
    vscaled15xGHIJKLMNOPQRSTUV = _mm512_mul_ps(vscaled15xGHIJKLMNOPQRSTUV, _mm512_set1_ps(quantization_params[15].inv_scale));
    vscaled15xWXYZabcdefghijkl = _mm512_mul_ps(vscaled15xWXYZabcdefghijkl, _mm512_set1_ps(quantization_params[15].inv_scale));
    vscaled15xmnopqrstuvwxyz01 = _mm512_mul_ps(vscaled15xmnopqrstuvwxyz01, _mm512_set1_ps(quantization_params[15].inv_scale));

    const __m512 vfilter_output_scale0123456789ABCDEF = _mm512_load_ps((const float*) w + 0);
    const __m512 vfilter_output_scaleGHIJKLMNOPQRSTUV = _mm512_load_ps((const float*) w + 16);
    const __m512 vfilter_output_scaleWXYZabcdefghijkl = _mm512_load_ps((const float*) w + 32);
    const __m512 vfilter_output_scalemnopqrstuvwxyz01 = _mm512_load_ps((const float*) w + 48);
    w = (const int32_t*) w + 64;
    const __m512 vbias0123456789ABCDEF = _mm512_load_ps((const float*) w + 0);
    const __m512 vbiasGHIJKLMNOPQRSTUV = _mm512_load_ps((const float*) w + 16);
    const __m512 vbiasWXYZabcdefghijkl = _mm512_load_ps((const float*) w + 32);
    const __m512 vbiasmnopqrstuvwxyz01 = _mm512_load_ps((const float*) w + 48);
    w = (const int32_t*) w + 64;

    vscaled0x0123456789ABCDEF = _mm512_fmadd_ps(vscaled0x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled0xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled0xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled0xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled0xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled0xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled0xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled1x0123456789ABCDEF = _mm512_fmadd_ps(vscaled1x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled1xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled1xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled1xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled1xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled1xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled1xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled2x0123456789ABCDEF = _mm512_fmadd_ps(vscaled2x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled2xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled2xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled2xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled2xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled2xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled2xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled3x0123456789ABCDEF = _mm512_fmadd_ps(vscaled3x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled3xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled3xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled3xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled3xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled3xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled3xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled4x0123456789ABCDEF = _mm512_fmadd_ps(vscaled4x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled4xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled4xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled4xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled4xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled4xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled4xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled5x0123456789ABCDEF = _mm512_fmadd_ps(vscaled5x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled5xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled5xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled5xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled5xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled5xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled5xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled6x0123456789ABCDEF = _mm512_fmadd_ps(vscaled6x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled6xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled6xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled6xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled6xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled6xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled6xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled7x0123456789ABCDEF = _mm512_fmadd_ps(vscaled7x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled7xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled7xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled7xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled7xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled7xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled7xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled8x0123456789ABCDEF = _mm512_fmadd_ps(vscaled8x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled8xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled8xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled8xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled8xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled8xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled8xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled9x0123456789ABCDEF = _mm512_fmadd_ps(vscaled9x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled9xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled9xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled9xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled9xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled9xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled9xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled10x0123456789ABCDEF = _mm512_fmadd_ps(vscaled10x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled10xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled10xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled10xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled10xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled10xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled10xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled11x0123456789ABCDEF = _mm512_fmadd_ps(vscaled11x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled11xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled11xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled11xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled11xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled11xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled11xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled12x0123456789ABCDEF = _mm512_fmadd_ps(vscaled12x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled12xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled12xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled12xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled12xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled12xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled12xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled13x0123456789ABCDEF = _mm512_fmadd_ps(vscaled13x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled13xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled13xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled13xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled13xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled13xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled13xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled14x0123456789ABCDEF = _mm512_fmadd_ps(vscaled14x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled14xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled14xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled14xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled14xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled14xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled14xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);
    vscaled15x0123456789ABCDEF = _mm512_fmadd_ps(vscaled15x0123456789ABCDEF, vfilter_output_scale0123456789ABCDEF, vbias0123456789ABCDEF);
    vscaled15xGHIJKLMNOPQRSTUV = _mm512_fmadd_ps(vscaled15xGHIJKLMNOPQRSTUV, vfilter_output_scaleGHIJKLMNOPQRSTUV, vbiasGHIJKLMNOPQRSTUV);
    vscaled15xWXYZabcdefghijkl = _mm512_fmadd_ps(vscaled15xWXYZabcdefghijkl, vfilter_output_scaleWXYZabcdefghijkl, vbiasWXYZabcdefghijkl);
    vscaled15xmnopqrstuvwxyz01 = _mm512_fmadd_ps(vscaled15xmnopqrstuvwxyz01, vfilter_output_scalemnopqrstuvwxyz01, vbiasmnopqrstuvwxyz01);

    vscaled0x0123456789ABCDEF = _mm512_max_ps(vscaled0x0123456789ABCDEF, voutput_min);
    vscaled0xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled0xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled0xWXYZabcdefghijkl = _mm512_max_ps(vscaled0xWXYZabcdefghijkl, voutput_min);
    vscaled0xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled0xmnopqrstuvwxyz01, voutput_min);
    vscaled1x0123456789ABCDEF = _mm512_max_ps(vscaled1x0123456789ABCDEF, voutput_min);
    vscaled1xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled1xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled1xWXYZabcdefghijkl = _mm512_max_ps(vscaled1xWXYZabcdefghijkl, voutput_min);
    vscaled1xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled1xmnopqrstuvwxyz01, voutput_min);
    vscaled2x0123456789ABCDEF = _mm512_max_ps(vscaled2x0123456789ABCDEF, voutput_min);
    vscaled2xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled2xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled2xWXYZabcdefghijkl = _mm512_max_ps(vscaled2xWXYZabcdefghijkl, voutput_min);
    vscaled2xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled2xmnopqrstuvwxyz01, voutput_min);
    vscaled3x0123456789ABCDEF = _mm512_max_ps(vscaled3x0123456789ABCDEF, voutput_min);
    vscaled3xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled3xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled3xWXYZabcdefghijkl = _mm512_max_ps(vscaled3xWXYZabcdefghijkl, voutput_min);
    vscaled3xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled3xmnopqrstuvwxyz01, voutput_min);
    vscaled4x0123456789ABCDEF = _mm512_max_ps(vscaled4x0123456789ABCDEF, voutput_min);
    vscaled4xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled4xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled4xWXYZabcdefghijkl = _mm512_max_ps(vscaled4xWXYZabcdefghijkl, voutput_min);
    vscaled4xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled4xmnopqrstuvwxyz01, voutput_min);
    vscaled5x0123456789ABCDEF = _mm512_max_ps(vscaled5x0123456789ABCDEF, voutput_min);
    vscaled5xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled5xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled5xWXYZabcdefghijkl = _mm512_max_ps(vscaled5xWXYZabcdefghijkl, voutput_min);
    vscaled5xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled5xmnopqrstuvwxyz01, voutput_min);
    vscaled6x0123456789ABCDEF = _mm512_max_ps(vscaled6x0123456789ABCDEF, voutput_min);
    vscaled6xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled6xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled6xWXYZabcdefghijkl = _mm512_max_ps(vscaled6xWXYZabcdefghijkl, voutput_min);
    vscaled6xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled6xmnopqrstuvwxyz01, voutput_min);
    vscaled7x0123456789ABCDEF = _mm512_max_ps(vscaled7x0123456789ABCDEF, voutput_min);
    vscaled7xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled7xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled7xWXYZabcdefghijkl = _mm512_max_ps(vscaled7xWXYZabcdefghijkl, voutput_min);
    vscaled7xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled7xmnopqrstuvwxyz01, voutput_min);
    vscaled8x0123456789ABCDEF = _mm512_max_ps(vscaled8x0123456789ABCDEF, voutput_min);
    vscaled8xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled8xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled8xWXYZabcdefghijkl = _mm512_max_ps(vscaled8xWXYZabcdefghijkl, voutput_min);
    vscaled8xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled8xmnopqrstuvwxyz01, voutput_min);
    vscaled9x0123456789ABCDEF = _mm512_max_ps(vscaled9x0123456789ABCDEF, voutput_min);
    vscaled9xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled9xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled9xWXYZabcdefghijkl = _mm512_max_ps(vscaled9xWXYZabcdefghijkl, voutput_min);
    vscaled9xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled9xmnopqrstuvwxyz01, voutput_min);
    vscaled10x0123456789ABCDEF = _mm512_max_ps(vscaled10x0123456789ABCDEF, voutput_min);
    vscaled10xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled10xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled10xWXYZabcdefghijkl = _mm512_max_ps(vscaled10xWXYZabcdefghijkl, voutput_min);
    vscaled10xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled10xmnopqrstuvwxyz01, voutput_min);
    vscaled11x0123456789ABCDEF = _mm512_max_ps(vscaled11x0123456789ABCDEF, voutput_min);
    vscaled11xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled11xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled11xWXYZabcdefghijkl = _mm512_max_ps(vscaled11xWXYZabcdefghijkl, voutput_min);
    vscaled11xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled11xmnopqrstuvwxyz01, voutput_min);
    vscaled12x0123456789ABCDEF = _mm512_max_ps(vscaled12x0123456789ABCDEF, voutput_min);
    vscaled12xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled12xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled12xWXYZabcdefghijkl = _mm512_max_ps(vscaled12xWXYZabcdefghijkl, voutput_min);
    vscaled12xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled12xmnopqrstuvwxyz01, voutput_min);
    vscaled13x0123456789ABCDEF = _mm512_max_ps(vscaled13x0123456789ABCDEF, voutput_min);
    vscaled13xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled13xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled13xWXYZabcdefghijkl = _mm512_max_ps(vscaled13xWXYZabcdefghijkl, voutput_min);
    vscaled13xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled13xmnopqrstuvwxyz01, voutput_min);
    vscaled14x0123456789ABCDEF = _mm512_max_ps(vscaled14x0123456789ABCDEF, voutput_min);
    vscaled14xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled14xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled14xWXYZabcdefghijkl = _mm512_max_ps(vscaled14xWXYZabcdefghijkl, voutput_min);
    vscaled14xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled14xmnopqrstuvwxyz01, voutput_min);
    vscaled15x0123456789ABCDEF = _mm512_max_ps(vscaled15x0123456789ABCDEF, voutput_min);
    vscaled15xGHIJKLMNOPQRSTUV = _mm512_max_ps(vscaled15xGHIJKLMNOPQRSTUV, voutput_min);
    vscaled15xWXYZabcdefghijkl = _mm512_max_ps(vscaled15xWXYZabcdefghijkl, voutput_min);
    vscaled15xmnopqrstuvwxyz01 = _mm512_max_ps(vscaled15xmnopqrstuvwxyz01, voutput_min);

    vscaled0x0123456789ABCDEF = _mm512_min_ps(vscaled0x0123456789ABCDEF, voutput_max);
    vscaled0xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled0xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled0xWXYZabcdefghijkl = _mm512_min_ps(vscaled0xWXYZabcdefghijkl, voutput_max);
    vscaled0xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled0xmnopqrstuvwxyz01, voutput_max);
    vscaled1x0123456789ABCDEF = _mm512_min_ps(vscaled1x0123456789ABCDEF, voutput_max);
    vscaled1xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled1xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled1xWXYZabcdefghijkl = _mm512_min_ps(vscaled1xWXYZabcdefghijkl, voutput_max);
    vscaled1xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled1xmnopqrstuvwxyz01, voutput_max);
    vscaled2x0123456789ABCDEF = _mm512_min_ps(vscaled2x0123456789ABCDEF, voutput_max);
    vscaled2xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled2xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled2xWXYZabcdefghijkl = _mm512_min_ps(vscaled2xWXYZabcdefghijkl, voutput_max);
    vscaled2xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled2xmnopqrstuvwxyz01, voutput_max);
    vscaled3x0123456789ABCDEF = _mm512_min_ps(vscaled3x0123456789ABCDEF, voutput_max);
    vscaled3xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled3xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled3xWXYZabcdefghijkl = _mm512_min_ps(vscaled3xWXYZabcdefghijkl, voutput_max);
    vscaled3xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled3xmnopqrstuvwxyz01, voutput_max);
    vscaled4x0123456789ABCDEF = _mm512_min_ps(vscaled4x0123456789ABCDEF, voutput_max);
    vscaled4xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled4xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled4xWXYZabcdefghijkl = _mm512_min_ps(vscaled4xWXYZabcdefghijkl, voutput_max);
    vscaled4xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled4xmnopqrstuvwxyz01, voutput_max);
    vscaled5x0123456789ABCDEF = _mm512_min_ps(vscaled5x0123456789ABCDEF, voutput_max);
    vscaled5xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled5xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled5xWXYZabcdefghijkl = _mm512_min_ps(vscaled5xWXYZabcdefghijkl, voutput_max);
    vscaled5xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled5xmnopqrstuvwxyz01, voutput_max);
    vscaled6x0123456789ABCDEF = _mm512_min_ps(vscaled6x0123456789ABCDEF, voutput_max);
    vscaled6xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled6xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled6xWXYZabcdefghijkl = _mm512_min_ps(vscaled6xWXYZabcdefghijkl, voutput_max);
    vscaled6xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled6xmnopqrstuvwxyz01, voutput_max);
    vscaled7x0123456789ABCDEF = _mm512_min_ps(vscaled7x0123456789ABCDEF, voutput_max);
    vscaled7xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled7xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled7xWXYZabcdefghijkl = _mm512_min_ps(vscaled7xWXYZabcdefghijkl, voutput_max);
    vscaled7xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled7xmnopqrstuvwxyz01, voutput_max);
    vscaled8x0123456789ABCDEF = _mm512_min_ps(vscaled8x0123456789ABCDEF, voutput_max);
    vscaled8xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled8xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled8xWXYZabcdefghijkl = _mm512_min_ps(vscaled8xWXYZabcdefghijkl, voutput_max);
    vscaled8xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled8xmnopqrstuvwxyz01, voutput_max);
    vscaled9x0123456789ABCDEF = _mm512_min_ps(vscaled9x0123456789ABCDEF, voutput_max);
    vscaled9xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled9xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled9xWXYZabcdefghijkl = _mm512_min_ps(vscaled9xWXYZabcdefghijkl, voutput_max);
    vscaled9xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled9xmnopqrstuvwxyz01, voutput_max);
    vscaled10x0123456789ABCDEF = _mm512_min_ps(vscaled10x0123456789ABCDEF, voutput_max);
    vscaled10xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled10xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled10xWXYZabcdefghijkl = _mm512_min_ps(vscaled10xWXYZabcdefghijkl, voutput_max);
    vscaled10xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled10xmnopqrstuvwxyz01, voutput_max);
    vscaled11x0123456789ABCDEF = _mm512_min_ps(vscaled11x0123456789ABCDEF, voutput_max);
    vscaled11xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled11xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled11xWXYZabcdefghijkl = _mm512_min_ps(vscaled11xWXYZabcdefghijkl, voutput_max);
    vscaled11xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled11xmnopqrstuvwxyz01, voutput_max);
    vscaled12x0123456789ABCDEF = _mm512_min_ps(vscaled12x0123456789ABCDEF, voutput_max);
    vscaled12xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled12xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled12xWXYZabcdefghijkl = _mm512_min_ps(vscaled12xWXYZabcdefghijkl, voutput_max);
    vscaled12xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled12xmnopqrstuvwxyz01, voutput_max);
    vscaled13x0123456789ABCDEF = _mm512_min_ps(vscaled13x0123456789ABCDEF, voutput_max);
    vscaled13xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled13xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled13xWXYZabcdefghijkl = _mm512_min_ps(vscaled13xWXYZabcdefghijkl, voutput_max);
    vscaled13xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled13xmnopqrstuvwxyz01, voutput_max);
    vscaled14x0123456789ABCDEF = _mm512_min_ps(vscaled14x0123456789ABCDEF, voutput_max);
    vscaled14xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled14xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled14xWXYZabcdefghijkl = _mm512_min_ps(vscaled14xWXYZabcdefghijkl, voutput_max);
    vscaled14xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled14xmnopqrstuvwxyz01, voutput_max);
    vscaled15x0123456789ABCDEF = _mm512_min_ps(vscaled15x0123456789ABCDEF, voutput_max);
    vscaled15xGHIJKLMNOPQRSTUV = _mm512_min_ps(vscaled15xGHIJKLMNOPQRSTUV, voutput_max);
    vscaled15xWXYZabcdefghijkl = _mm512_min_ps(vscaled15xWXYZabcdefghijkl, voutput_max);
    vscaled15xmnopqrstuvwxyz01 = _mm512_min_ps(vscaled15xmnopqrstuvwxyz01, voutput_max);

    __m256i vfp16out0x0123456789ABCDEF = _mm512_cvtps_ph(vscaled0x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out0xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled0xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out0xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled0xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out0xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled0xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out1x0123456789ABCDEF = _mm512_cvtps_ph(vscaled1x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out1xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled1xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out1xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled1xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out1xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled1xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out2x0123456789ABCDEF = _mm512_cvtps_ph(vscaled2x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out2xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled2xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out2xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled2xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out2xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled2xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out3x0123456789ABCDEF = _mm512_cvtps_ph(vscaled3x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out3xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled3xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out3xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled3xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out3xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled3xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out4x0123456789ABCDEF = _mm512_cvtps_ph(vscaled4x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out4xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled4xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out4xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled4xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out4xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled4xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out5x0123456789ABCDEF = _mm512_cvtps_ph(vscaled5x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out5xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled5xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out5xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled5xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out5xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled5xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out6x0123456789ABCDEF = _mm512_cvtps_ph(vscaled6x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out6xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled6xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out6xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled6xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out6xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled6xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out7x0123456789ABCDEF = _mm512_cvtps_ph(vscaled7x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out7xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled7xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out7xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled7xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out7xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled7xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out8x0123456789ABCDEF = _mm512_cvtps_ph(vscaled8x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out8xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled8xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out8xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled8xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out8xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled8xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out9x0123456789ABCDEF = _mm512_cvtps_ph(vscaled9x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out9xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled9xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out9xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled9xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out9xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled9xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out10x0123456789ABCDEF = _mm512_cvtps_ph(vscaled10x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out10xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled10xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out10xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled10xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out10xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled10xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out11x0123456789ABCDEF = _mm512_cvtps_ph(vscaled11x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out11xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled11xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out11xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled11xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out11xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled11xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out12x0123456789ABCDEF = _mm512_cvtps_ph(vscaled12x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out12xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled12xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out12xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled12xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out12xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled12xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out13x0123456789ABCDEF = _mm512_cvtps_ph(vscaled13x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out13xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled13xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out13xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled13xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out13xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled13xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out14x0123456789ABCDEF = _mm512_cvtps_ph(vscaled14x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out14xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled14xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out14xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled14xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out14xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled14xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out15x0123456789ABCDEF = _mm512_cvtps_ph(vscaled15x0123456789ABCDEF, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out15xGHIJKLMNOPQRSTUV = _mm512_cvtps_ph(vscaled15xGHIJKLMNOPQRSTUV, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out15xWXYZabcdefghijkl = _mm512_cvtps_ph(vscaled15xWXYZabcdefghijkl, _MM_FROUND_TO_NEAREST_INT);
    __m256i vfp16out15xmnopqrstuvwxyz01 = _mm512_cvtps_ph(vscaled15xmnopqrstuvwxyz01, _MM_FROUND_TO_NEAREST_INT);
    if XNN_LIKELY(nc >= 64) {
      _mm256_storeu_si256((__m256i*) (c15 + 0), vfp16out15x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c15 + 16), vfp16out15xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c15 + 32), vfp16out15xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c15 + 48), vfp16out15xmnopqrstuvwxyz01);
      c15 = (xnn_float16*) ((uintptr_t) c15 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c14 + 0), vfp16out14x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c14 + 16), vfp16out14xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c14 + 32), vfp16out14xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c14 + 48), vfp16out14xmnopqrstuvwxyz01);
      c14 = (xnn_float16*) ((uintptr_t) c14 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c13 + 0), vfp16out13x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c13 + 16), vfp16out13xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c13 + 32), vfp16out13xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c13 + 48), vfp16out13xmnopqrstuvwxyz01);
      c13 = (xnn_float16*) ((uintptr_t) c13 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c12 + 0), vfp16out12x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c12 + 16), vfp16out12xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c12 + 32), vfp16out12xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c12 + 48), vfp16out12xmnopqrstuvwxyz01);
      c12 = (xnn_float16*) ((uintptr_t) c12 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c11 + 0), vfp16out11x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c11 + 16), vfp16out11xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c11 + 32), vfp16out11xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c11 + 48), vfp16out11xmnopqrstuvwxyz01);
      c11 = (xnn_float16*) ((uintptr_t) c11 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c10 + 0), vfp16out10x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c10 + 16), vfp16out10xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c10 + 32), vfp16out10xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c10 + 48), vfp16out10xmnopqrstuvwxyz01);
      c10 = (xnn_float16*) ((uintptr_t) c10 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c9 + 0), vfp16out9x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c9 + 16), vfp16out9xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c9 + 32), vfp16out9xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c9 + 48), vfp16out9xmnopqrstuvwxyz01);
      c9 = (xnn_float16*) ((uintptr_t) c9 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c8 + 0), vfp16out8x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c8 + 16), vfp16out8xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c8 + 32), vfp16out8xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c8 + 48), vfp16out8xmnopqrstuvwxyz01);
      c8 = (xnn_float16*) ((uintptr_t) c8 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c7 + 0), vfp16out7x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c7 + 16), vfp16out7xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c7 + 32), vfp16out7xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c7 + 48), vfp16out7xmnopqrstuvwxyz01);
      c7 = (xnn_float16*) ((uintptr_t) c7 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c6 + 0), vfp16out6x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c6 + 16), vfp16out6xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c6 + 32), vfp16out6xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c6 + 48), vfp16out6xmnopqrstuvwxyz01);
      c6 = (xnn_float16*) ((uintptr_t) c6 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c5 + 0), vfp16out5x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c5 + 16), vfp16out5xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c5 + 32), vfp16out5xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c5 + 48), vfp16out5xmnopqrstuvwxyz01);
      c5 = (xnn_float16*) ((uintptr_t) c5 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c4 + 0), vfp16out4x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c4 + 16), vfp16out4xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c4 + 32), vfp16out4xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c4 + 48), vfp16out4xmnopqrstuvwxyz01);
      c4 = (xnn_float16*) ((uintptr_t) c4 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c3 + 0), vfp16out3x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c3 + 16), vfp16out3xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c3 + 32), vfp16out3xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c3 + 48), vfp16out3xmnopqrstuvwxyz01);
      c3 = (xnn_float16*) ((uintptr_t) c3 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c2 + 0), vfp16out2x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c2 + 16), vfp16out2xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c2 + 32), vfp16out2xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c2 + 48), vfp16out2xmnopqrstuvwxyz01);
      c2 = (xnn_float16*) ((uintptr_t) c2 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c1 + 0), vfp16out1x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c1 + 16), vfp16out1xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c1 + 32), vfp16out1xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c1 + 48), vfp16out1xmnopqrstuvwxyz01);
      c1 = (xnn_float16*) ((uintptr_t) c1 + cn_stride);
      _mm256_storeu_si256((__m256i*) (c0 + 0), vfp16out0x0123456789ABCDEF);
      _mm256_storeu_si256((__m256i*) (c0 + 16), vfp16out0xGHIJKLMNOPQRSTUV);
      _mm256_storeu_si256((__m256i*) (c0 + 32), vfp16out0xWXYZabcdefghijkl);
      _mm256_storeu_si256((__m256i*) (c0 + 48), vfp16out0xmnopqrstuvwxyz01);
      c0 = (xnn_float16*) ((uintptr_t) c0 + cn_stride);

      a -= kc;
      nc -= 64;
    } else {
      // Prepare mask for valid 32-bit elements (depends on nc).
      const __mmask16 vmask0 = _cvtu32_mask16((uint32_t) ((((UINT64_C(1) << nc) - 1) >> 0) & 0xFFFF));
      const __mmask16 vmask1 = _cvtu32_mask16((uint32_t) ((((UINT64_C(1) << nc) - 1) >> 16) & 0xFFFF));
      const __mmask16 vmask2 = _cvtu32_mask16((uint32_t) ((((UINT64_C(1) << nc) - 1) >> 32) & 0xFFFF));
      const __mmask16 vmask3 = _cvtu32_mask16((uint32_t) ((((UINT64_C(1) << nc) - 1) >> 48) & 0xFFFF));
      _mm256_mask_storeu_epi16(c15 + 0, vmask0, vfp16out15x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c15 + 16, vmask1, vfp16out15xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c15 + 32, vmask2, vfp16out15xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c15 + 48, vmask3, vfp16out15xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c14 + 0, vmask0, vfp16out14x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c14 + 16, vmask1, vfp16out14xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c14 + 32, vmask2, vfp16out14xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c14 + 48, vmask3, vfp16out14xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c13 + 0, vmask0, vfp16out13x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c13 + 16, vmask1, vfp16out13xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c13 + 32, vmask2, vfp16out13xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c13 + 48, vmask3, vfp16out13xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c12 + 0, vmask0, vfp16out12x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c12 + 16, vmask1, vfp16out12xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c12 + 32, vmask2, vfp16out12xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c12 + 48, vmask3, vfp16out12xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c11 + 0, vmask0, vfp16out11x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c11 + 16, vmask1, vfp16out11xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c11 + 32, vmask2, vfp16out11xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c11 + 48, vmask3, vfp16out11xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c10 + 0, vmask0, vfp16out10x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c10 + 16, vmask1, vfp16out10xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c10 + 32, vmask2, vfp16out10xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c10 + 48, vmask3, vfp16out10xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c9 + 0, vmask0, vfp16out9x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c9 + 16, vmask1, vfp16out9xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c9 + 32, vmask2, vfp16out9xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c9 + 48, vmask3, vfp16out9xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c8 + 0, vmask0, vfp16out8x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c8 + 16, vmask1, vfp16out8xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c8 + 32, vmask2, vfp16out8xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c8 + 48, vmask3, vfp16out8xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c7 + 0, vmask0, vfp16out7x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c7 + 16, vmask1, vfp16out7xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c7 + 32, vmask2, vfp16out7xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c7 + 48, vmask3, vfp16out7xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c6 + 0, vmask0, vfp16out6x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c6 + 16, vmask1, vfp16out6xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c6 + 32, vmask2, vfp16out6xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c6 + 48, vmask3, vfp16out6xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c5 + 0, vmask0, vfp16out5x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c5 + 16, vmask1, vfp16out5xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c5 + 32, vmask2, vfp16out5xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c5 + 48, vmask3, vfp16out5xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c4 + 0, vmask0, vfp16out4x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c4 + 16, vmask1, vfp16out4xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c4 + 32, vmask2, vfp16out4xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c4 + 48, vmask3, vfp16out4xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c3 + 0, vmask0, vfp16out3x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c3 + 16, vmask1, vfp16out3xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c3 + 32, vmask2, vfp16out3xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c3 + 48, vmask3, vfp16out3xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c2 + 0, vmask0, vfp16out2x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c2 + 16, vmask1, vfp16out2xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c2 + 32, vmask2, vfp16out2xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c2 + 48, vmask3, vfp16out2xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c1 + 0, vmask0, vfp16out1x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c1 + 16, vmask1, vfp16out1xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c1 + 32, vmask2, vfp16out1xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c1 + 48, vmask3, vfp16out1xmnopqrstuvwxyz01);
      _mm256_mask_storeu_epi16(c0 + 0, vmask0, vfp16out0x0123456789ABCDEF);
      _mm256_mask_storeu_epi16(c0 + 16, vmask1, vfp16out0xGHIJKLMNOPQRSTUV);
      _mm256_mask_storeu_epi16(c0 + 32, vmask2, vfp16out0xWXYZabcdefghijkl);
      _mm256_mask_storeu_epi16(c0 + 48, vmask3, vfp16out0xmnopqrstuvwxyz01);
      nc = 0;
    }
  } while (nc != 0);
  // Release tile config
  _tile_release();
  #endif  // defined(__x86_64__)
}
