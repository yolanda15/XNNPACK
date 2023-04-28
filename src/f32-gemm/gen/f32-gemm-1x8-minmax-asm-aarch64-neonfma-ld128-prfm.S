// Auto-generated file. Do not edit!
//   Template: src/f32-gemm/1x8-aarch64-neonfma-ld128.S.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <xnnpack/assembly.h>

# void xnn_f32_gemm_minmax_ukernel_1x8__asm_aarch64_neonfma_ld128_prfm(
#     size_t mr,                (x0) - unused.  mr = 1
#     size_t nc,                x1
#     size_t kc,                x2 / x0
#     const uint8_t*restrict a, x3
#     size_t a_stride,          (x4) - unused
#     const void*restrict w,    x5
#     uint8_t*restrict c,       x6
#     size_t cm_stride,         (x7) - unused
#     size_t cn_stride,         [sp] -> x14
#     const union xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)])  [sp + 8] -> (x8)

# d8-d15, x19-x30 need to be preserved if used. x18 is reserved by the OS.

# Register usage
# A0  x3 v0
# B   x5 v24 v25
#        v26 v27
#        v28 v29
#        v30 v31
# C0  x6 v16 v17
#        v18 v19 acc2
# Clamp  v4, v5

BEGIN_FUNCTION xnn_f32_gemm_minmax_ukernel_1x8__asm_aarch64_neonfma_ld128_prfm

        # Load cn_stride, params pointer
        LDP     x14, x8, [sp]

        # Load min/max values
        LD2R    {v4.4s, v5.4s}, [x8]
0:
        # Load initial bias from w into accumulators
        LDP     q16, q17, [x5], 32

        MOVI    v18.4s, 0               // zero accumulators for pipelining FMA
        PRFM    PLDL1KEEP, [x5]
        MOVI    v19.4s, 0
        PRFM    PLDL1KEEP, [x5, 64]
        MOVI    v20.4s, 0
        PRFM    PLDL1KEEP, [x5, 128]
        MOVI    v21.4s, 0
        PRFM    PLDL1KEEP, [x5, 192]
        MOVI    v22.4s, 0
        MOVI    v23.4s, 0

        # Is there at least 4 floats (16 bytes) for main loop?
        SUBS    x0, x2, 16              // k = kc - 16
        B.LO    5f


        # Main loop - 4 floats of A (16 bytes)
1:
        LDP     q24, q25, [x5], 32
        LDP     q26, q27, [x5], 32
        LDR     q0, [x3], 16
        LDP     q28, q29, [x5], 32
        LDP     q30, q31, [x5], 32
        SUBS    x0, x0, 16
        FMLA    v16.4s, v24.4s, v0.s[0]
        FMLA    v17.4s, v25.4s, v0.s[0]
        PRFM    PLDL1KEEP, [x5, 128]
        FMLA    v18.4s, v26.4s, v0.s[1]
        FMLA    v19.4s, v27.4s, v0.s[1]
        PRFM    PLDL1KEEP, [x5, 192]
        FMLA    v16.4s, v28.4s, v0.s[2]
        FMLA    v17.4s, v29.4s, v0.s[2]
        FMLA    v18.4s, v30.4s, v0.s[3]
        FMLA    v19.4s, v31.4s, v0.s[3]
        B.HS    1b

3:
        # Is there a remainder?- 2 floats of A (8 bytes)
        TBNZ    x0, 3, 6f
        # Is there a remainder?- 1 float of A (4 bytes)
        TBNZ    x0, 2, 8f

4:
        FADD    v16.4s, v16.4s, v18.4s
        FADD    v17.4s, v17.4s, v19.4s
        SUBS    x1, x1, 8

        # Clamp
        FMAX    v16.4s, v16.4s, v4.4s
        FMAX    v17.4s, v17.4s, v4.4s
        FMIN    v16.4s, v16.4s, v5.4s
        FMIN    v17.4s, v17.4s, v5.4s

        # Store full 1 x 8
        B.LO    9f

        STP     q16, q17, [x6]
        ADD     x6, x6, x14

        SUB     x3,  x3, x2             // a0 -= kc
        B.HI    0b

        RET

5:
        TBZ     x0, 3, 7f
6:
        # Remainder- 2 floats of A (8 bytes)
        LDR     d0, [x3], 8
        LDP     q24, q25, [x5], 32
        LDP     q26, q27, [x5], 32
        FMLA    v16.4s, v24.4s, v0.s[0]
        FMLA    v17.4s, v25.4s, v0.s[0]
        FMLA    v18.4s, v26.4s, v0.s[1]
        FMLA    v19.4s, v27.4s, v0.s[1]
7:
        TBZ     x0, 2, 4b
8:
        # Remainder- 1 float of A (4 bytes)
        LDR     s0, [x3], 4
        LDP     q24, q25, [x5], 32
        FMLA    v16.4s, v24.4s, v0.s[0]
        FMLA    v17.4s, v25.4s, v0.s[0]
        B       4b

        # Store odd channels
9:
        TBZ     x1, 2, 10f
        STR     q16, [x6], 16
        MOV     v16.16b, v17.16b

10:
        TBZ     x1, 1, 11f
        STR     d16, [x6], 8
        DUP     d16, v16.d[1]

11:
        TBZ     x1, 0, 12f
        STR     s16, [x6]
12:
        RET

END_FUNCTION xnn_f32_gemm_minmax_ukernel_1x8__asm_aarch64_neonfma_ld128_prfm

#ifdef __ELF__
.section ".note.GNU-stack","",%progbits
#endif