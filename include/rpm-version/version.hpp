// SPDX-license-identifier: Apache-2.0 OR GPL-2.0
// Copyright © 2021-2022 Intel Corporation

/**
 * C++ API for RPMVersion
 */

#pragma once

#include <string>

namespace RPMVersion {

/// What kind of operation is being done
enum class Operator {
    /// Less than
    LT,
    /// Less than or equal
    LE,
    /// equal
    NE,
    /// Not Equal
    EQ,
    /// Greater than or equal
    GE,
    /// Greater than
    GT,
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