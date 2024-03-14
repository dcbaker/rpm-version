// SPDX-License-Identifier: Apache-2.0 OR GPL-2.0
// Copyright © 2021-2024 Intel Corporation

/**
 * C++ API for RPMVersion
 */

#pragma once

#include <string>

namespace RPMVersion {

/// What kind of operation is being done
enum class Operator {
    /// Less than
    lt,
    /// Less than or equal
    le,
    /// equal
    ne,
    /// Not Equal
    eq,
    /// Greater than or equal
    ge,
    /// Greater than
    gt,
};

/**
 * Compare two versions, with the given comparison operator
 *
 * @param ver1 The first version to compare
 * @param cmp  The comparison operator to use
 * @param ver2 The first version to compare
 * @return True if the comparison is successful, otherwise false
 */
bool compare(std::string_view ver1, const Operator op, std::string_view ver2);

} // namespace RPMVersion