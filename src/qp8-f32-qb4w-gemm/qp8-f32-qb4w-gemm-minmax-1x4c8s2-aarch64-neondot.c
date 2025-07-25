// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <stddef.h>
#include "src/xnnpack/microparams.h"

#if XNN_ENABLE_KLEIDIAI
  #include "kai/ukernels/matmul/matmul_clamp_f32_qai8dxp_qsi4c32p/kai_matmul_clamp_f32_qai8dxp1x4_qsi4c32p4x4_1x4_neon_dotprod.h"
#endif // XNN_ENABLE_KLEIDIAI

void xnn_qp8_f32_qb4w_gemm_minmax_ukernel_1x4c8s2__aarch64_neondot(
    size_t m, size_t n, size_t k, const void* lhs_packed,
    const void* rhs_packed, float* dst, size_t dst_stride_row,
    size_t dst_stride_col,
    const struct xnn_f32_qb4w_minmax_params* minmax_params) {
#if XNN_ENABLE_KLEIDIAI
  kai_run_matmul_clamp_f32_qai8dxp1x4_qsi4c32p4x4_1x4_neon_dotprod(
      m, n, k, minmax_params->scalar.blocksize, lhs_packed, rhs_packed, dst, dst_stride_row, dst_stride_col,
      minmax_params->scalar.min, minmax_params->scalar.max);
#else
  assert(
      "Calling KleidiAI microkernel wrapper, but XNNPACK was compiled without "
      "`XNN_ENABLE_KLEIDIAI`." && 0);
#endif  // XNN_ENABLE_KLEIDIAI
}
