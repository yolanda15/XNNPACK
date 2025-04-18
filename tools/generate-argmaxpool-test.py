#!/usr/bin/env python
# Copyright 2019 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

import argparse
import codecs
import math
import os
import re
import sys
import yaml

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from primes import next_prime
import xngen
import xnncommon


parser = argparse.ArgumentParser(
    description="ArgMaxPool microkernel test generator"
)
parser.add_argument(
    "-s",
    "--spec",
    metavar="FILE",
    required=True,
    help="Specification (YAML) file",
)
parser.add_argument(
    "-o",
    "--output",
    metavar="FILE",
    required=True,
    help="Output (C++ source) file",
)
parser.set_defaults(defines=list())


def split_ukernel_name(name):
  match = re.fullmatch(
      r"xnn_(f16|f32)_argmaxpool_ukernel_((\d+)p)?(\d+)x__(.+)_(c)?(u)?(\d+)(v)?",
      name,
  )
  if match is None:
    raise ValueError("Unexpected microkernel name: " + name)

  if match.group(2):
    primary_tile = int(match.group(3))
    incremental_tile = int(match.group(4))
  else:
    primary_tile = int(match.group(4))
    incremental_tile = 0

  channel_tile = int(match.group(8))
  vector_tile = bool(match.group(9))

  arch, isa, assembly = xnncommon.parse_target_name(target_name=match.group(5))
  return primary_tile, incremental_tile, channel_tile, vector_tile, arch, isa


ARGMAXPOOL_TEST_TEMPLATE = """\
TEST(${TEST_NAME}, channels_eq_${CHANNEL_TILE}${CHANNEL_SUFFIX}_onetile) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  const size_t channel_tile = ${CHANNEL_SCALED_TILE};
  ArgMaxPoolMicrokernelTester()
    .pooling_elements(${PRIMARY_TILE})
    .channels(channel_tile)
    .Test(${", ".join(TEST_ARGS)});
}

TEST(${TEST_NAME}, channels_eq_${CHANNEL_TILE}${CHANNEL_SUFFIX}_onetile_with_input_offset) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  const size_t channel_tile = ${CHANNEL_SCALED_TILE};
  ArgMaxPoolMicrokernelTester()
    .pooling_elements(${PRIMARY_TILE})
    .channels(channel_tile)
    $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
      .input_offset(${next_prime(CHANNEL_TILE+1)})
    $else:
      .input_offset(channel_tile+1)
    .Test(${", ".join(TEST_ARGS)});
}

TEST(${TEST_NAME}, channels_eq_${CHANNEL_TILE}${CHANNEL_SUFFIX}_subtile) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  const size_t channel_tile = ${CHANNEL_SCALED_TILE};
  for (size_t pooling_elements = 2; pooling_elements < ${PRIMARY_TILE}; pooling_elements++) {
    ArgMaxPoolMicrokernelTester()
      .pooling_elements(pooling_elements)
      .channels(channel_tile)
      .Test(${", ".join(TEST_ARGS)});
  }
}

TEST(${TEST_NAME}, channels_eq_${CHANNEL_TILE}${CHANNEL_SUFFIX}_subtile_with_input_offset) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  const size_t channel_tile = ${CHANNEL_SCALED_TILE};
  for (size_t pooling_elements = 2; pooling_elements < ${PRIMARY_TILE}; pooling_elements++) {
    ArgMaxPoolMicrokernelTester()
      .pooling_elements(pooling_elements)
      .channels(channel_tile)
      $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
        .input_offset(${next_prime(CHANNEL_TILE+1)})
      $else:
        .input_offset(channel_tile+1)
      .Test(${", ".join(TEST_ARGS)});
  }
}

TEST(${TEST_NAME}, channels_eq_${CHANNEL_TILE}${CHANNEL_SUFFIX}_multitile) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  const size_t channel_tile = ${CHANNEL_SCALED_TILE};
  for (size_t pooling_elements = 2; pooling_elements <= 3 * ${PRIMARY_TILE}; pooling_elements++) {
    ArgMaxPoolMicrokernelTester()
      .pooling_elements(pooling_elements)
      .channels(channel_tile)
      .Test(${", ".join(TEST_ARGS)});
  }
}

TEST(${TEST_NAME}, channels_eq_${CHANNEL_TILE}${CHANNEL_SUFFIX}_multitile_with_input_offset) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  const size_t channel_tile = ${CHANNEL_SCALED_TILE};
  for (size_t pooling_elements = 2; pooling_elements <= 3 * ${PRIMARY_TILE}; pooling_elements++) {
    ArgMaxPoolMicrokernelTester()
      .pooling_elements(pooling_elements)
      .channels(channel_tile)
      $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
        .input_offset(${next_prime(CHANNEL_TILE+1)})
      $else:
        .input_offset(channel_tile+1)
      .Test(${", ".join(TEST_ARGS)});
  }
}

$if CHANNEL_TILE > 1 or CHANNEL_SCALED_TILE != CHANNEL_TILE:
  TEST(${TEST_NAME}, channels_div_${CHANNEL_TILE}${CHANNEL_SUFFIX}_onetile) {
    $if ISA_CHECK:
      ${ISA_CHECK};
    $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
      for (size_t channels = ${CHANNEL_TILE * 2}; channels < ${CHANNEL_TILE * 8}; channels += ${CHANNEL_TILE}) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(${PRIMARY_TILE})
          .channels(channels)
          .Test(${", ".join(TEST_ARGS)});
      }
    $else:
      const size_t channel_tile = ${CHANNEL_SCALED_TILE};
      for (size_t channels = channel_tile * 2; channels < channel_tile * ${3 if 'RVV' in TEST_NAME else 8}; channels += channel_tile) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(${PRIMARY_TILE})
          .channels(channels)
          .Test(${", ".join(TEST_ARGS)});
      }
  }

  TEST(${TEST_NAME}, channels_div_${CHANNEL_TILE}${CHANNEL_SUFFIX}_onetile_with_input_offset) {
    $if ISA_CHECK:
      ${ISA_CHECK};
    $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
      for (size_t channels = ${CHANNEL_TILE * 2}; channels < ${CHANNEL_TILE * 8}; channels += ${CHANNEL_TILE}) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(${PRIMARY_TILE})
          .channels(channels)
          .input_offset(${next_prime(CHANNEL_TILE * 8)})
          .Test(${", ".join(TEST_ARGS)});
      }
    $else:
      const size_t channel_tile = ${CHANNEL_SCALED_TILE};
      for (size_t channels = channel_tile * 2; channels < channel_tile * ${3 if 'RVV' in TEST_NAME else 8}; channels += channel_tile) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(${PRIMARY_TILE})
          .channels(channels)
          .input_offset(channel_tile * 8)
          .Test(${", ".join(TEST_ARGS)});
      }
  }

  TEST(${TEST_NAME}, channels_div_${CHANNEL_TILE}${CHANNEL_SUFFIX}_subtile) {
    $if ISA_CHECK:
      ${ISA_CHECK};
    for (size_t pooling_elements = 2; pooling_elements < ${PRIMARY_TILE}; pooling_elements++) {
      $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
        for (size_t channels = ${CHANNEL_TILE * 2}; channels < ${CHANNEL_TILE * 8}; channels += ${CHANNEL_TILE}) {
          ArgMaxPoolMicrokernelTester()
            .pooling_elements(pooling_elements)
            .channels(channels)
            .Test(${", ".join(TEST_ARGS)});
        }
      $else:
        const size_t channel_tile = ${CHANNEL_SCALED_TILE};
        for (size_t channels = channel_tile * 2; channels < channel_tile * ${3 if 'RVV' in TEST_NAME else 8}; channels += channel_tile) {
          ArgMaxPoolMicrokernelTester()
            .pooling_elements(pooling_elements)
            .channels(channels)
            .Test(${", ".join(TEST_ARGS)});
        }
    }
  }

  TEST(${TEST_NAME}, channels_div_${CHANNEL_TILE}${CHANNEL_SUFFIX}_subtile_with_input_offset) {
    $if ISA_CHECK:
      ${ISA_CHECK};
    for (size_t pooling_elements = 2; pooling_elements < ${PRIMARY_TILE}; pooling_elements++) {
      $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
        for (size_t channels = ${CHANNEL_TILE * 2}; channels < ${CHANNEL_TILE * 8}; channels += ${CHANNEL_TILE}) {
          ArgMaxPoolMicrokernelTester()
            .pooling_elements(pooling_elements)
            .channels(channels)
            .input_offset(${next_prime(CHANNEL_TILE * 8)})
            .Test(${", ".join(TEST_ARGS)});
        }
      $else:
        const size_t channel_tile = ${CHANNEL_SCALED_TILE};
        for (size_t channels = channel_tile * 2; channels < channel_tile * ${3 if 'RVV' in TEST_NAME else 8}; channels += channel_tile) {
          ArgMaxPoolMicrokernelTester()
            .pooling_elements(pooling_elements)
            .channels(channels)
            .input_offset(channel_tile * 8)
            .Test(${", ".join(TEST_ARGS)});
        }
    }
  }




  TEST(${TEST_NAME}, channels_div_${CHANNEL_TILE}${CHANNEL_SUFFIX}_multitile) {
    $if ISA_CHECK:
      ${ISA_CHECK};
    for (size_t pooling_elements = 2; pooling_elements <= 3 * ${PRIMARY_TILE}; pooling_elements++) {
      $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
        for (size_t channels = ${CHANNEL_TILE * 2}; channels < ${CHANNEL_TILE * 8}; channels += ${CHANNEL_TILE}) {
          ArgMaxPoolMicrokernelTester()
            .pooling_elements(pooling_elements)
            .channels(channels)
            .Test(${", ".join(TEST_ARGS)});
        }
      $else:
        const size_t channel_tile = ${CHANNEL_SCALED_TILE};
        for (size_t channels = channel_tile * 2; channels < channel_tile * ${3 if 'RVV' in TEST_NAME else 8}; channels += channel_tile) {
          ArgMaxPoolMicrokernelTester()
            .pooling_elements(pooling_elements)
            .channels(channels)
            .Test(${", ".join(TEST_ARGS)});
        }
    }
  }

  TEST(${TEST_NAME}, channels_div_${CHANNEL_TILE}${CHANNEL_SUFFIX}_multitile_with_input_offset) {
    $if ISA_CHECK:
      ${ISA_CHECK};
    for (size_t pooling_elements = 2; pooling_elements <= 3 * ${PRIMARY_TILE}; pooling_elements++) {
      $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
        for (size_t channels = ${CHANNEL_TILE * 2}; channels < ${CHANNEL_TILE * 8}; channels += ${CHANNEL_TILE}) {
          ArgMaxPoolMicrokernelTester()
            .pooling_elements(pooling_elements)
            .channels(channels)
            .input_offset(${next_prime(CHANNEL_TILE * 8)})
            .Test(${", ".join(TEST_ARGS)});
        }
      $else:
        const size_t channel_tile = ${CHANNEL_SCALED_TILE};
        for (size_t channels = channel_tile * 2; channels < channel_tile * ${3 if 'RVV' in TEST_NAME else 8}; channels += channel_tile) {
          ArgMaxPoolMicrokernelTester()
            .pooling_elements(pooling_elements)
            .channels(channels)
            .input_offset(channel_tile * 8)
            .Test(${", ".join(TEST_ARGS)});
        }
    }
  }



  TEST(${TEST_NAME}, channels_lt_${CHANNEL_TILE}${CHANNEL_SUFFIX}_onetile) {
    $if ISA_CHECK:
      ${ISA_CHECK};
    const size_t channel_tile = ${CHANNEL_SCALED_TILE};
    for (size_t channels = 1; channels < channel_tile; channels++) {
      ArgMaxPoolMicrokernelTester()
        .pooling_elements(${PRIMARY_TILE})
        .channels(channels)
        .Test(${", ".join(TEST_ARGS)});
    }
  }

  TEST(${TEST_NAME}, channels_lt_${CHANNEL_TILE}${CHANNEL_SUFFIX}_onetile_with_input_offset) {
    $if ISA_CHECK:
      ${ISA_CHECK};
    const size_t channel_tile = ${CHANNEL_SCALED_TILE};
    for (size_t channels = 1; channels < channel_tile; channels++) {
      ArgMaxPoolMicrokernelTester()
        .pooling_elements(${PRIMARY_TILE})
        .channels(channels)
        $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
          .input_offset(${next_prime(CHANNEL_TILE)})
        $else:
          .input_offset(channel_tile)
        .Test(${", ".join(TEST_ARGS)});
    }
  }

  TEST(${TEST_NAME}, channels_lt_${CHANNEL_TILE}${CHANNEL_SUFFIX}_subtile) {
    $if ISA_CHECK:
      ${ISA_CHECK};
    const size_t channel_tile = ${CHANNEL_SCALED_TILE};
    for (size_t pooling_elements = 2; pooling_elements < ${PRIMARY_TILE}; pooling_elements++) {
      for (size_t channels = 1; channels < channel_tile; channels++) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(pooling_elements)
          .channels(channels)
          .Test(${", ".join(TEST_ARGS)});
      }
    }
  }

  TEST(${TEST_NAME}, channels_lt_${CHANNEL_TILE}${CHANNEL_SUFFIX}_subtile_with_input_offset) {
    $if ISA_CHECK:
      ${ISA_CHECK};
    const size_t channel_tile = ${CHANNEL_SCALED_TILE};
    for (size_t pooling_elements = 2; pooling_elements < ${PRIMARY_TILE}; pooling_elements++) {
      for (size_t channels = 1; channels < channel_tile; channels++) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(pooling_elements)
          .channels(channels)
          $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
            .input_offset(${next_prime(CHANNEL_TILE)})
          $else:
            .input_offset(channel_tile)
          .Test(${", ".join(TEST_ARGS)});
      }
    }
  }

TEST(${TEST_NAME}, channels_gt_${CHANNEL_TILE}${CHANNEL_SUFFIX}_onetile) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
    for (size_t channels = ${CHANNEL_TILE+1}; channels < ${10 if CHANNEL_TILE == 1 else CHANNEL_TILE * 2}; channels++) {
      ArgMaxPoolMicrokernelTester()
        .pooling_elements(${PRIMARY_TILE})
        .channels(channels)
        .Test(${", ".join(TEST_ARGS)});
    }
  $else:
    const size_t channel_tile = ${CHANNEL_SCALED_TILE};
    for (size_t channels = channel_tile+1; channels < channel_tile * 2; channels++) {
      ArgMaxPoolMicrokernelTester()
        .pooling_elements(${PRIMARY_TILE})
        .channels(channels)
        .Test(${", ".join(TEST_ARGS)});
    }
}

TEST(${TEST_NAME}, channels_gt_${CHANNEL_TILE}${CHANNEL_SUFFIX}_onetile_with_input_offset) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
    for (size_t channels = ${CHANNEL_TILE+1}; channels < ${10 if CHANNEL_TILE == 1 else CHANNEL_TILE * 2}; channels++) {
      ArgMaxPoolMicrokernelTester()
        .pooling_elements(${PRIMARY_TILE})
        .channels(channels)
        .input_offset(${next_prime(CHANNEL_TILE * 2)})
        .Test(${", ".join(TEST_ARGS)});
    }
  $else:
    const size_t channel_tile = ${CHANNEL_SCALED_TILE};
    for (size_t channels = channel_tile+1; channels < channel_tile * 2; channels++) {
      ArgMaxPoolMicrokernelTester()
        .pooling_elements(${PRIMARY_TILE})
        .channels(channels)
        .input_offset(channel_tile * 2)
        .Test(${", ".join(TEST_ARGS)});
    }
}

TEST(${TEST_NAME}, channels_gt_${CHANNEL_TILE}${CHANNEL_SUFFIX}_subtile) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t pooling_elements = 2; pooling_elements < ${PRIMARY_TILE}; pooling_elements++) {
    $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
      for (size_t channels = ${CHANNEL_TILE+1}; channels < ${10 if CHANNEL_TILE == 1 else CHANNEL_TILE * 2}; channels++) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(pooling_elements)
          .channels(channels)
          .Test(${", ".join(TEST_ARGS)});
      }
    $else:
      const size_t channel_tile = ${CHANNEL_SCALED_TILE};
      for (size_t channels = channel_tile+1; channels < channel_tile * 2; channels++) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(pooling_elements)
          .channels(channels)
          .Test(${", ".join(TEST_ARGS)});
      }
  }
}

TEST(${TEST_NAME}, channels_gt_${CHANNEL_TILE}${CHANNEL_SUFFIX}_subtile_with_input_offset) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t pooling_elements = 2; pooling_elements < ${PRIMARY_TILE}; pooling_elements++) {
    $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
      for (size_t channels = ${CHANNEL_TILE+1}; channels < ${10 if CHANNEL_TILE == 1 else CHANNEL_TILE * 2}; channels++) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(pooling_elements)
          .channels(channels)
          .input_offset(${next_prime(CHANNEL_TILE * 2)})
          .Test(${", ".join(TEST_ARGS)});
      }
    $else:
      const size_t channel_tile = ${CHANNEL_SCALED_TILE};
      for (size_t channels = channel_tile+1; channels < channel_tile * 2; channels++) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(pooling_elements)
          .channels(channels)
          .input_offset(channel_tile * 2)
          .Test(${", ".join(TEST_ARGS)});
      }
  }
}


TEST(${TEST_NAME}, channels_gt_${CHANNEL_TILE}${CHANNEL_SUFFIX}_multitile) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t pooling_elements = 2; pooling_elements <= 3 * ${PRIMARY_TILE}; pooling_elements++) {
    $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
      for (size_t channels = ${CHANNEL_TILE+1}; channels < ${10 if CHANNEL_TILE == 1 else CHANNEL_TILE * 2}; channels++) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(pooling_elements)
          .channels(channels)
          .Test(${", ".join(TEST_ARGS)});
      }
    $else:
      const size_t channel_tile = ${CHANNEL_SCALED_TILE};
      for (size_t channels = channel_tile+1; channels < channel_tile * 2; channels++) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(pooling_elements)
          .channels(channels)
          .Test(${", ".join(TEST_ARGS)});
      }
  }
}

TEST(${TEST_NAME}, channels_gt_${CHANNEL_TILE}${CHANNEL_SUFFIX}_multitile_with_input_offset) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t pooling_elements = 2; pooling_elements <= 3 * ${PRIMARY_TILE}; pooling_elements++) {
    $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
      for (size_t channels = ${CHANNEL_TILE+1}; channels < ${10 if CHANNEL_TILE == 1 else CHANNEL_TILE * 2}; channels++) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(pooling_elements)
          .channels(channels)
          .input_offset(${next_prime(CHANNEL_TILE * 2)})
          .Test(${", ".join(TEST_ARGS)});
      }
    $else:
      const size_t channel_tile = ${CHANNEL_SCALED_TILE};
      for (size_t channels = channel_tile+1; channels < channel_tile * 2; channels++) {
        ArgMaxPoolMicrokernelTester()
          .pooling_elements(pooling_elements)
          .channels(channels)
          .input_offset(channel_tile * 2)
          .Test(${", ".join(TEST_ARGS)});
      }
  }
}

$MIN_POOLING, MAX_POOLING = 2, 25

TEST(${TEST_NAME}, few_output_pixels) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t output_pixels = 2; output_pixels <= 5; output_pixels++) {
    for (size_t pooling_elements = ${MIN_POOLING}; pooling_elements <= ${MAX_POOLING}; pooling_elements = xnnpack::NextPrime(pooling_elements)) {
      $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
        for (size_t channels = 1; channels <= ${CHANNEL_TILE * 5}; channels += ${max(1, CHANNEL_TILE-1)}) {
          ArgMaxPoolMicrokernelTester()
            .output_pixels(output_pixels)
            .pooling_elements(pooling_elements)
            .channels(channels)
            .Test(${", ".join(TEST_ARGS)});
        }
      $else:
        const size_t channel_tile = ${CHANNEL_SCALED_TILE};
        for (size_t channels = 1; channels <= channel_tile * 5; channels += channel_tile-1) {
          ArgMaxPoolMicrokernelTester()
            .output_pixels(output_pixels)
            .pooling_elements(pooling_elements)
            .channels(channels)
            .Test(${", ".join(TEST_ARGS)});
        }
    }
  }
}

TEST(${TEST_NAME}, few_output_pixels_with_input_offset) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t output_pixels = 2; output_pixels <= 5; output_pixels++) {
    for (size_t pooling_elements = ${MIN_POOLING}; pooling_elements <= ${MAX_POOLING}; pooling_elements = xnnpack::NextPrime(pooling_elements)) {
      $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
        for (size_t channels = 1; channels <= ${CHANNEL_TILE * 5}; channels += ${max(1, CHANNEL_TILE-1)}) {
          ArgMaxPoolMicrokernelTester()
            .output_pixels(output_pixels)
            .pooling_elements(pooling_elements)
            .channels(channels)
            .input_offset(${next_prime(CHANNEL_TILE * 5+1)})
            .Test(${", ".join(TEST_ARGS)});
        }
      $else:
        const size_t channel_tile = ${CHANNEL_SCALED_TILE};
        for (size_t channels = 1; channels <= channel_tile * 5; channels += channel_tile-1) {
          ArgMaxPoolMicrokernelTester()
            .output_pixels(output_pixels)
            .pooling_elements(pooling_elements)
            .channels(channels)
            .input_offset(channel_tile * 5+1)
            .Test(${", ".join(TEST_ARGS)});
        }
    }
  }
}

TEST(${TEST_NAME}, few_output_pixels_with_output_stride) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t output_pixels = 2; output_pixels <= 5; output_pixels++) {
    for (size_t pooling_elements = ${MIN_POOLING}; pooling_elements <= ${MAX_POOLING}; pooling_elements = xnnpack::NextPrime(pooling_elements)) {
      $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
        for (size_t channels = 1; channels <= ${CHANNEL_TILE * 5}; channels += ${max(1, CHANNEL_TILE-1)}) {
          ArgMaxPoolMicrokernelTester()
            .output_pixels(output_pixels)
            .pooling_elements(pooling_elements)
            .channels(channels)
            .output_stride(${next_prime(CHANNEL_TILE * 5+1)})
            .Test(${", ".join(TEST_ARGS)});
        }
      $else:
        const size_t channel_tile = ${CHANNEL_SCALED_TILE};
        for (size_t channels = 1; channels <= channel_tile * 5; channels += channel_tile-1) {
          ArgMaxPoolMicrokernelTester()
            .output_pixels(output_pixels)
            .pooling_elements(pooling_elements)
            .channels(channels)
            .output_stride(channel_tile * 5+1)
            .Test(${", ".join(TEST_ARGS)});
        }
    }
  }
}

TEST(${TEST_NAME}, few_output_pixels_with_step) {
  $if ISA_CHECK:
    ${ISA_CHECK};
  for (size_t output_pixels = 2; output_pixels <= 5; output_pixels++) {
    for (size_t pooling_elements = ${MIN_POOLING}; pooling_elements <= ${MAX_POOLING}; pooling_elements = xnnpack::NextPrime(pooling_elements)) {
      $if CHANNEL_SCALED_TILE == CHANNEL_TILE:
        for (size_t channels = 1; channels <= ${CHANNEL_TILE * 5}; channels += ${max(1, CHANNEL_TILE-1)}) {
          for (size_t step = 2; step <= pooling_elements; step++) {
            ArgMaxPoolMicrokernelTester()
              .output_pixels(output_pixels)
              .pooling_elements(pooling_elements)
              .step(step)
              .channels(channels)
              .output_stride(${next_prime(CHANNEL_TILE * 5+1)})
              .Test(${", ".join(TEST_ARGS)});
          }
        }
      $else:
        const size_t channel_tile = ${CHANNEL_SCALED_TILE};
        for (size_t channels = 1; channels <= channel_tile * 5; channels += channel_tile-1) {
          for (size_t step = 2; step <= pooling_elements; step++) {
            ArgMaxPoolMicrokernelTester()
              .output_pixels(output_pixels)
              .pooling_elements(pooling_elements)
              .step(step)
              .channels(channels)
              .output_stride(channel_tile * 5+1)
              .Test(${", ".join(TEST_ARGS)});
          }
        }
    }
  }
}
"""


def generate_test_cases(
    ukernel, primary_tile, incremental_tile, channel_tile, vector_tile, isa
):
  """Generates all tests cases for a ARGMAXPOOL micro-kernel.

  Args:
    ukernel: C name of the micro-kernel function.
    primary_tile: Number of rows (pixels) processed per one iteration of the
      primary outer loop of the micro-kernel.
    incremental_tile: Number of rows (pixels) processed per one iteration of the
      incremental outer loop of the micro-kernel.
    channel_tile: Number of channels processed per one iteration of the inner
      loops of the micro-kernel.
    vector_tile: Indicates if channels are specified in vectors rather than
      elements.
    isa: instruction set required to run the micro-kernel. Generated unit test
      will skip execution if the host processor doesn't support this ISA.

  Returns:
    Code for the test case.
  """
  _, test_name = ukernel.split("_", 1)
  _, datatype, ukernel_type, _ = ukernel.split("_", 3)
  test_args = [ukernel]
  channel_scaled_tile = channel_tile
  if vector_tile:
    ctype = {"f16": "uint16_t", "f32": "float"}[datatype]
    channel_scaled_tile = {
        "rvv": (
            "(%s * xnn_init_hardware_config()->vlenb / sizeof(%s))"
            % (str(channel_tile), ctype)
        )
    }[isa]
  return xngen.preprocess(
      ARGMAXPOOL_TEST_TEMPLATE,
      {
          "TEST_NAME": test_name.upper().replace("UKERNEL_", ""),
          "TEST_ARGS": test_args,
          "DATATYPE": datatype,
          "PRIMARY_TILE": primary_tile,
          "INCREMENTAL_TILE": incremental_tile,
          "CHANNEL_TILE": channel_tile,
          "CHANNEL_SCALED_TILE": channel_scaled_tile,
          "CHANNEL_SUFFIX": "v" if vector_tile else "",
          "ISA_CHECK": xnncommon.generate_isa_check_macro(isa),
          "next_prime": next_prime,
      },
  )


def main(args):
  options = parser.parse_args(args)

  with codecs.open(options.spec, "r", encoding="utf-8") as spec_file:
    spec_yaml = yaml.safe_load(spec_file)
    if not isinstance(spec_yaml, list):
      raise ValueError("expected a list of micro-kernels in the spec")

    tests = """\
// clang-format off
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: {specification}
//   Generator: {generator}


#include <gtest/gtest.h>
#include "src/xnnpack/argmaxpool.h"
#include "src/xnnpack/common.h"
#include "src/xnnpack/isa-checks.h"
#include "test/argmaxpool-microkernel-tester.h"
#include "test/next_prime.h"
""".format(specification=options.spec, generator=sys.argv[0])

    for ukernel_spec in spec_yaml:
      name = ukernel_spec["name"]
      primary_tile, incremental_tile, channel_tile, vector_tile, arch, isa = (
          split_ukernel_name(name)
      )

      test_case = generate_test_cases(
          name, primary_tile, incremental_tile, channel_tile, vector_tile, isa
      )
      tests += "\n\n" + xnncommon.postprocess_test_case(test_case, arch, isa)

    xnncommon.overwrite_if_changed(options.output, tests)


if __name__ == "__main__":
  main(sys.argv[1:])
