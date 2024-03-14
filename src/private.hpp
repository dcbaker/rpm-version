// SPDX-License-Identifier: Apache-2.0 OR GPL-2.0
// Copyright © 2021-2024 Intel Corporation

#pragma once

#include <string>

#include "rpm-version/version.hpp"

namespace RPMVersion {

std::string to_string(const Operator op);

void assert_fn(bool expr, const char * msg);

} // namespace RPMVersion

#if RPM_VERSION_HAS_UNREACHABLE
#define RPM_VERSION_UNREACHABLE(msg)                                                               \
    do {                                                                                           \
        RPMVersion::assert_fn(false, msg);                                                         \
        __builtin_unreachable();                                                                   \
    } while (false)
#else
#define RPM_VERSION_UNREACHABLE(msg) RPMVersion::assert_fn(false);
#endif