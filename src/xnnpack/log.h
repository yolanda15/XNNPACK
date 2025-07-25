// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#ifndef XNNPACK_SRC_XNNPACK_LOG_H_
#define XNNPACK_SRC_XNNPACK_LOG_H_

#include <stdarg.h>
#include <stdlib.h>

#include "include/xnnpack.h"
#include "src/xnnpack/common.h"

#ifndef XNN_LOG_LEVEL
#error "Undefined XNN_LOG_LEVEL"
#endif

#define XNN_LOG_NONE 0
#define XNN_LOG_FATAL 1
#define XNN_LOG_ERROR 2
#define XNN_LOG_WARNING 3
#define XNN_LOG_INFO 4
#define XNN_LOG_DEBUG 5

#ifdef __cplusplus
extern "C" {
#endif

#if XNN_LOG_LEVEL >= XNN_LOG_DEBUG
void xnn_vlog_debug(const char* format, va_list args);
#endif

#if XNN_LOG_LEVEL >= XNN_LOG_INFO
void xnn_vlog_info(const char* format, va_list args);
#endif

#if XNN_LOG_LEVEL >= XNN_LOG_WARNING
void xnn_vlog_warning(const char* format, va_list args);
#endif

#if XNN_LOG_LEVEL >= XNN_LOG_ERROR
void xnn_vlog_error(const char* format, va_list args);
#endif

#if XNN_LOG_LEVEL >= XNN_LOG_FATAL
void xnn_vlog_fatal(const char* format, va_list args);
#endif

const char* xnn_datatype_to_string(enum xnn_datatype type);

#ifdef __cplusplus
}  // extern "C"
#endif

#ifndef XNN_LOG_ARGUMENTS_FORMAT
#ifdef __GNUC__
#define XNN_LOG_ARGUMENTS_FORMAT __attribute__((__format__(__printf__, 1, 2)))
#else
#define XNN_LOG_ARGUMENTS_FORMAT
#endif
#endif

#if XNN_LOG_LEVEL >= XNN_LOG_DEBUG
#define xnn_log_debug(format, ...)                                             \
  xnn_log_debug_(format " (%s, %s:%i)", ##__VA_ARGS__, __FUNCTION__, __FILE__, \
                 __LINE__)

XNN_LOG_ARGUMENTS_FORMAT inline static void xnn_log_debug_(const char* format,
                                                           ...) {
  va_list args;
  va_start(args, format);
  xnn_vlog_debug(format, args);
  va_end(args);
}
#else
#define xnn_log_debug(format, ...)
#endif  // XNN_LOG_LEVEL >= XNN_LOG_DEBUG

#if XNN_LOG_LEVEL >= XNN_LOG_INFO
#define xnn_log_info(format, ...)                                             \
  xnn_log_info_(format " (%s, %s:%i)", ##__VA_ARGS__, __FUNCTION__, __FILE__, \
                __LINE__)

XNN_LOG_ARGUMENTS_FORMAT inline static void xnn_log_info_(const char* format,
                                                          ...) {
  va_list args;
  va_start(args, format);
  xnn_vlog_info(format, args);
  va_end(args);
}
#else
#define xnn_log_info(format, ...)
#endif  // XNN_LOG_LEVEL >= XNN_LOG_INFO

#if XNN_LOG_LEVEL >= XNN_LOG_WARNING
#define xnn_log_warning(format, ...)                                   \
  xnn_log_warning_(format " (%s, %s:%i)", ##__VA_ARGS__, __FUNCTION__, \
                   __FILE__, __LINE__)

XNN_LOG_ARGUMENTS_FORMAT inline static void xnn_log_warning_(const char* format,
                                                             ...) {
  va_list args;
  va_start(args, format);
  xnn_vlog_warning(format, args);
  va_end(args);
}
#else
#define xnn_log_warning(format, ...)
#endif  // XNN_LOG_LEVEL >= XNN_LOG_WARNING

#if XNN_LOG_LEVEL >= XNN_LOG_ERROR
#define xnn_log_error(format, ...)                                             \
  xnn_log_error_(format " (%s, %s:%i)", ##__VA_ARGS__, __FUNCTION__, __FILE__, \
                 __LINE__)

XNN_LOG_ARGUMENTS_FORMAT inline static void xnn_log_error_(const char* format,
                                                           ...) {
  va_list args;
  va_start(args, format);
  xnn_vlog_error(format, args);
  va_end(args);
}
#else
#define xnn_log_error(format, ...)
#endif  // XNN_LOG_LEVEL >= XNN_LOG_ERROR

#if XNN_LOG_LEVEL >= XNN_LOG_FATAL
#define xnn_log_fatal(format, ...)                                             \
  xnn_log_fatal_(format " (%s, %s:%i)", ##__VA_ARGS__, __FUNCTION__, __FILE__, \
                 __LINE__)

XNN_LOG_ARGUMENTS_FORMAT inline static void xnn_log_fatal_(const char* format,
                                                           ...) {
  va_list args;
  va_start(args, format);
  xnn_vlog_fatal(format, args);
  va_end(args);
  abort();
}
#else
#define xnn_log_fatal(format, ...) abort()
#endif  // XNN_LOG_LEVEL >= XNN_LOG_FATAL

#if XNN_LOG_LEVEL >= XNN_LOG_DEBUG
#define XNN_LOG_UNREACHABLE(...) \
  do {                           \
    xnn_log_fatal(__VA_ARGS__);  \
  } while (0)
#else
#define XNN_LOG_UNREACHABLE(...) XNN_UNREACHABLE
#endif

#endif  // XNNPACK_SRC_XNNPACK_LOG_H_
