/*
 * Copyright 2019 Google LLC
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

/* mock crypto module for benchmarks and unit tests or std::random_device fails at runtime */
var crypto = { getRandomValues: function(array) { for (var i = 0; i < array.length; i++) array[i] = (Math.random()*256)|0 } };
if (typeof performance === 'undefined') {
    if (ENVIRONMENT_IS_NODE && require) {
        var performance = require('node:perf_hooks').performance
    } else {
        var performance = { now: Date.now, timeOrigin: Date.now() }
    }
}