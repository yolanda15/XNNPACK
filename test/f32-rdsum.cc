// clang-format off
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: test/f32-rdsum.yaml
//   Generator: tools/generate-reduce-discontiguous-test.py


#include <gtest/gtest.h>
#include "src/xnnpack/common.h"
#include "src/xnnpack/isa-checks.h"
#include "src/xnnpack/microparams-init.h"
#include "src/xnnpack/reduce.h"
#include "test/rdsum-microkernel-tester.h"


TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_eq_4_2pass_fulltile) {
  const size_t channel_tile = 4;
  RDSumMicrokernelTester()
    .rows(14)
    .channels(channel_tile)
    .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_eq_4_2pass_fulltile_with_input_stride) {
  const size_t channel_tile = 4;
  RDSumMicrokernelTester()
    .rows(14)
    .channels(channel_tile)
    .input_stride(7)
    .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_eq_4_2pass_subtile) {
  const size_t channel_tile = 4;
  for (size_t rows = 1; rows < 14; rows++) {
    RDSumMicrokernelTester()
      .rows(rows)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_eq_4_2pass_subtile_with_input_stride) {
  const size_t channel_tile = 4;
  for (size_t rows = 1; rows < 14; rows++) {
    RDSumMicrokernelTester()
      .rows(rows)
      .channels(channel_tile)
      .input_stride(7)
      .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_eq_4_multipass_fulltile) {
  const size_t channel_tile = 4;
  for (size_t rows = 1; rows <= 35; rows += 7) {
    RDSumMicrokernelTester()
      .rows(rows)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_eq_4_multipass_fulltile_with_input_stride) {
  const size_t channel_tile = 4;
  for (size_t rows = 1; rows <= 35; rows += 7) {
    RDSumMicrokernelTester()
      .rows(rows)
      .channels(channel_tile)
      .input_stride(7)
      .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_div_4_2pass_fulltile) {
  for (size_t channels = 8; channels < 32; channels += 4) {
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channels)
      .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_div_4_2pass_subtile) {
  for (size_t channels = 8; channels < 32; channels += 4) {
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
    }
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_div_4_multipass_fulltile) {
  for (size_t channels = 8; channels < 32; channels += 4) {
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
    }
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_div_4_multipass_fulltile_with_input_stride) {
  for (size_t channels = 8; channels < 32; channels += 4) {
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channels)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
    }
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_lt_4_2pass_fulltile) {
  const size_t channel_tile = 4;
  for (size_t channels = 1; channels < channel_tile; channels++) {
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channels)
      .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_lt_4_2pass_subtile) {
  const size_t channel_tile = 4;
  for (size_t channels = 1; channels < channel_tile; channels++) {
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
    }
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_lt_4_multipass_fulltile) {
  const size_t channel_tile = 4;
  for (size_t channels = 1; channels < channel_tile; channels++) {
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
    }
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_lt_4_multipass_fulltile_with_input_stride) {
  const size_t channel_tile = 4;
  for (size_t channels = 1; channels < channel_tile; channels++) {
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channels)
        .input_stride(7)
        .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
    }
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_gt_4_2pass_fulltile) {
  for (size_t channels = 5; channels < 8; channels++) {
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channels)
      .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_gt_4_2pass_subtile) {
  for (size_t channels = 5; channels < 8; channels++) {
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
    }
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_gt_4_multipass_fulltile) {
  for (size_t channels = 5; channels < 8; channels++) {
    for (size_t rows = 1; rows < 35; rows += 14) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
    }
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, channels_gt_4_multipass_fulltile_with_input_stride) {
  for (size_t channels = 5; channels < 8; channels++) {
    for (size_t rows = 1; rows < 35; rows += 14) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channels)
        .input_stride(23)
        .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
    }
  }
}

TEST(F32_RDSUM_7P7X__SCALAR_C4, overflow_accumulator) {
  const size_t channel_tile = 4;
  for (size_t channels = 1; channels < channel_tile*2; ++channels) {
     RDSumMicrokernelTester()
       .rows(264)
       .channels(channels)
       .Test(xnn_f32_rdsum_ukernel_7p7x__scalar_c4, xnn_init_f32_scale_scalar_params);
  }
}

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_RDSUM_7P7X__NEON_C16, channels_eq_16_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_eq_16_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(19)
      .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_eq_16_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_eq_16_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(19)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_eq_16_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_eq_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(19)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_div_16_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 32; channels < 128; channels += 16) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_div_16_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_div_16_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_div_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(263)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_lt_16_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_lt_16_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_lt_16_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_lt_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(19)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_gt_16_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 17; channels < 32; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_gt_16_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_gt_16_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, channels_gt_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(47)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C16, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c16, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_RDSUM_7P7X__NEON_C32, channels_eq_32_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_eq_32_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(37)
      .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_eq_32_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_eq_32_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(37)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_eq_32_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_eq_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(37)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_div_32_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 64; channels < 256; channels += 32) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_div_32_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_div_32_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_div_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(521)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_lt_32_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_lt_32_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_lt_32_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_lt_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(37)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_gt_32_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 33; channels < 64; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_gt_32_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_gt_32_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, channels_gt_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(79)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C32, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c32, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_RDSUM_7P7X__NEON_C64, channels_eq_64_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_eq_64_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(67)
      .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_eq_64_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_eq_64_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_eq_64_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_eq_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_div_64_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 128; channels < 512; channels += 64) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_div_64_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_div_64_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_div_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(1031)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_lt_64_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_lt_64_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_lt_64_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_lt_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(67)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_gt_64_2pass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 65; channels < 128; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_gt_64_2pass_subtile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_gt_64_multipass_fulltile) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, channels_gt_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(149)
          .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__NEON_C64, overflow_accumulator) {
    TEST_REQUIRES_ARM_NEON;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__neon_c64, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV
  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_eq_1v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_eq_1v_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(channel_tile+1)
      .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_eq_1v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_eq_1v_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(channel_tile+1)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_eq_1v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_eq_1v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(channel_tile+1)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_div_1v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_div_1v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_div_1v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_div_1v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(channel_tile*16+1)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_lt_1v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_lt_1v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_lt_1v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_lt_1v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(channel_tile+1)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_gt_1v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_gt_1v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_gt_1v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, channels_gt_1v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(channel_tile*2+11)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U1V, overflow_accumulator) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (1*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u1v, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV


#if XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV
  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_eq_2v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_eq_2v_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(channel_tile+1)
      .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_eq_2v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_eq_2v_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(channel_tile+1)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_eq_2v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_eq_2v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(channel_tile+1)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_div_2v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_div_2v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_div_2v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_div_2v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(channel_tile*16+1)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_lt_2v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_lt_2v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_lt_2v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_lt_2v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(channel_tile+1)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_gt_2v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_gt_2v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_gt_2v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, channels_gt_2v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(channel_tile*2+11)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U2V, overflow_accumulator) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (2*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u2v, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV


#if XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV
  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_eq_4v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_eq_4v_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(channel_tile+1)
      .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_eq_4v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_eq_4v_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(channel_tile+1)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_eq_4v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_eq_4v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(channel_tile+1)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_div_4v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_div_4v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_div_4v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_div_4v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile*2; channels < channel_tile*8; channels += channel_tile) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(channel_tile*16+1)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_lt_4v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_lt_4v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_lt_4v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_lt_4v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(channel_tile+1)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_gt_4v_2pass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_gt_4v_2pass_subtile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_gt_4v_multipass_fulltile) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, channels_gt_4v_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = channel_tile+1; channels < channel_tile*2; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(channel_tile*2+11)
          .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__RVV_U4V, overflow_accumulator) {
    TEST_REQUIRES_RISCV_VECTOR;
    const size_t channel_tile = (4*xnn_init_hardware_config()->vlenb/sizeof(float));
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__rvv_u4v, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ENABLE_RISCV_VECTOR && XNN_ARCH_RISCV


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RDSUM_7P7X__SSE_C16, channels_eq_16_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_eq_16_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(19)
      .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_eq_16_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_eq_16_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(19)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_eq_16_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_eq_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(19)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_div_16_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 32; channels < 128; channels += 16) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_div_16_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_div_16_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_div_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(263)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_lt_16_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_lt_16_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_lt_16_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_lt_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(19)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_gt_16_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 17; channels < 32; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_gt_16_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_gt_16_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, channels_gt_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(47)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C16, overflow_accumulator) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c16, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RDSUM_7P7X__SSE_C32, channels_eq_32_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_eq_32_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(37)
      .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_eq_32_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_eq_32_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(37)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_eq_32_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_eq_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(37)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_div_32_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 64; channels < 256; channels += 32) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_div_32_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_div_32_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_div_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(521)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_lt_32_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_lt_32_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_lt_32_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_lt_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(37)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_gt_32_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 33; channels < 64; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_gt_32_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_gt_32_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, channels_gt_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(79)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C32, overflow_accumulator) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c32, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RDSUM_7P7X__SSE_C64, channels_eq_64_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_eq_64_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(67)
      .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_eq_64_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_eq_64_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_eq_64_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_eq_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_div_64_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 128; channels < 512; channels += 64) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_div_64_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_div_64_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_div_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(1031)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_lt_64_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_lt_64_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_lt_64_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_lt_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(67)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_gt_64_2pass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 65; channels < 128; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_gt_64_2pass_subtile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_gt_64_multipass_fulltile) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, channels_gt_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_SSE;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(149)
          .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__SSE_C64, overflow_accumulator) {
    TEST_REQUIRES_X86_SSE;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__sse_c64, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RDSUM_7P7X__AVX_C16, channels_eq_16_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_eq_16_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(19)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_eq_16_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_eq_16_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(19)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_eq_16_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_eq_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(19)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_div_16_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 32; channels < 128; channels += 16) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_div_16_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_div_16_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_div_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(263)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_lt_16_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_lt_16_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_lt_16_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_lt_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(19)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_gt_16_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 17; channels < 32; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_gt_16_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_gt_16_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, channels_gt_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(47)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C16, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c16, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RDSUM_7P7X__AVX_C32, channels_eq_32_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_eq_32_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(37)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_eq_32_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_eq_32_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(37)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_eq_32_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_eq_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(37)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_div_32_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 64; channels < 256; channels += 32) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_div_32_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_div_32_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_div_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(521)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_lt_32_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_lt_32_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_lt_32_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_lt_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(37)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_gt_32_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 33; channels < 64; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_gt_32_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_gt_32_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, channels_gt_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(79)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C32, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c32, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RDSUM_7P7X__AVX_C64, channels_eq_64_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_eq_64_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(67)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_eq_64_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_eq_64_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_eq_64_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_eq_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_div_64_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 128; channels < 512; channels += 64) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_div_64_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_div_64_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_div_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(1031)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_lt_64_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_lt_64_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_lt_64_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_lt_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(67)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_gt_64_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 65; channels < 128; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_gt_64_2pass_subtile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_gt_64_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, channels_gt_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(149)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX_C64, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__avx_c64, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_eq_16_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_eq_16_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(19)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_eq_16_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_eq_16_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(19)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_eq_16_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_eq_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(19)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_div_16_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 32; channels < 128; channels += 16) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_div_16_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_div_16_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_div_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(263)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_lt_16_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_lt_16_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_lt_16_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_lt_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(19)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_gt_16_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 17; channels < 32; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_gt_16_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_gt_16_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, channels_gt_16_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(47)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C16, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c16, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_eq_32_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_eq_32_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(37)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_eq_32_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_eq_32_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(37)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_eq_32_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_eq_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(37)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_div_32_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 64; channels < 256; channels += 32) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_div_32_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_div_32_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_div_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(521)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_lt_32_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_lt_32_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_lt_32_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_lt_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(37)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_gt_32_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 33; channels < 64; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_gt_32_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_gt_32_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, channels_gt_32_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(79)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C32, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c32, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_eq_64_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_eq_64_2pass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(67)
      .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_eq_64_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_eq_64_2pass_subtile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_eq_64_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_eq_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_div_64_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 128; channels < 512; channels += 64) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_div_64_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_div_64_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_div_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(1031)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_lt_64_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_lt_64_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_lt_64_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_lt_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(67)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_gt_64_2pass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 65; channels < 128; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_gt_64_2pass_subtile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_gt_64_multipass_fulltile) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, channels_gt_64_multipass_fulltile_with_input_stride) {
    TEST_REQUIRES_X86_AVX512F;
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(149)
          .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__AVX512F_C64, overflow_accumulator) {
    TEST_REQUIRES_X86_AVX512F;
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__avx512f_c64, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_eq_16_2pass_fulltile) {
    const size_t channel_tile = 16;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_eq_16_2pass_fulltile_with_input_stride) {
    const size_t channel_tile = 16;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(19)
      .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_eq_16_2pass_subtile) {
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_eq_16_2pass_subtile_with_input_stride) {
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(19)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_eq_16_multipass_fulltile) {
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_eq_16_multipass_fulltile_with_input_stride) {
    const size_t channel_tile = 16;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(19)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_div_16_2pass_fulltile) {
    for (size_t channels = 32; channels < 128; channels += 16) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_div_16_2pass_subtile) {
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_div_16_multipass_fulltile) {
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_div_16_multipass_fulltile_with_input_stride) {
    for (size_t channels = 32; channels < 128; channels += 16) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(263)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_lt_16_2pass_fulltile) {
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_lt_16_2pass_subtile) {
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_lt_16_multipass_fulltile) {
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_lt_16_multipass_fulltile_with_input_stride) {
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(19)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_gt_16_2pass_fulltile) {
    for (size_t channels = 17; channels < 32; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_gt_16_2pass_subtile) {
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_gt_16_multipass_fulltile) {
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, channels_gt_16_multipass_fulltile_with_input_stride) {
    for (size_t channels = 17; channels < 32; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(47)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C16, overflow_accumulator) {
    const size_t channel_tile = 16;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c16, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_eq_32_2pass_fulltile) {
    const size_t channel_tile = 32;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_eq_32_2pass_fulltile_with_input_stride) {
    const size_t channel_tile = 32;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(37)
      .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_eq_32_2pass_subtile) {
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_eq_32_2pass_subtile_with_input_stride) {
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(37)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_eq_32_multipass_fulltile) {
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_eq_32_multipass_fulltile_with_input_stride) {
    const size_t channel_tile = 32;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(37)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_div_32_2pass_fulltile) {
    for (size_t channels = 64; channels < 256; channels += 32) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_div_32_2pass_subtile) {
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_div_32_multipass_fulltile) {
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_div_32_multipass_fulltile_with_input_stride) {
    for (size_t channels = 64; channels < 256; channels += 32) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(521)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_lt_32_2pass_fulltile) {
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_lt_32_2pass_subtile) {
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_lt_32_multipass_fulltile) {
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_lt_32_multipass_fulltile_with_input_stride) {
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(37)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_gt_32_2pass_fulltile) {
    for (size_t channels = 33; channels < 64; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_gt_32_2pass_subtile) {
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_gt_32_multipass_fulltile) {
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, channels_gt_32_multipass_fulltile_with_input_stride) {
    for (size_t channels = 33; channels < 64; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(79)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C32, overflow_accumulator) {
    const size_t channel_tile = 32;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c32, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_eq_64_2pass_fulltile) {
    const size_t channel_tile = 64;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_eq_64_2pass_fulltile_with_input_stride) {
    const size_t channel_tile = 64;
    RDSumMicrokernelTester()
      .rows(14)
      .channels(channel_tile)
      .input_stride(67)
      .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_eq_64_2pass_subtile) {
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_eq_64_2pass_subtile_with_input_stride) {
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows < 14; rows++) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_eq_64_multipass_fulltile) {
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_eq_64_multipass_fulltile_with_input_stride) {
    const size_t channel_tile = 64;
    for (size_t rows = 1; rows <= 35; rows += 7) {
      RDSumMicrokernelTester()
        .rows(rows)
        .channels(channel_tile)
        .input_stride(67)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_div_64_2pass_fulltile) {
    for (size_t channels = 128; channels < 512; channels += 64) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_div_64_2pass_subtile) {
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_div_64_multipass_fulltile) {
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_div_64_multipass_fulltile_with_input_stride) {
    for (size_t channels = 128; channels < 512; channels += 64) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(1031)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_lt_64_2pass_fulltile) {
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_lt_64_2pass_subtile) {
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_lt_64_multipass_fulltile) {
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_lt_64_multipass_fulltile_with_input_stride) {
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile; channels++) {
      for (size_t rows = 1; rows <= 35; rows += 7) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(67)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_gt_64_2pass_fulltile) {
    for (size_t channels = 65; channels < 128; channels++) {
      RDSumMicrokernelTester()
        .rows(14)
        .channels(channels)
        .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_gt_64_2pass_subtile) {
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 14; rows++) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_gt_64_multipass_fulltile) {
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, channels_gt_64_multipass_fulltile_with_input_stride) {
    for (size_t channels = 65; channels < 128; channels++) {
      for (size_t rows = 1; rows < 35; rows += 14) {
        RDSumMicrokernelTester()
          .rows(rows)
          .channels(channels)
          .input_stride(149)
          .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
      }
    }
  }

  TEST(F32_RDSUM_7P7X__WASMSIMD_C64, overflow_accumulator) {
    const size_t channel_tile = 64;
    for (size_t channels = 1; channels < channel_tile*2; ++channels) {
       RDSumMicrokernelTester()
         .rows(264)
         .channels(channels)
         .Test(xnn_f32_rdsum_ukernel_7p7x__wasmsimd_c64, xnn_init_f32_scale_scalar_params);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
