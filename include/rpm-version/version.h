/* SPDX-license-identifier: Apache-2.0 OR GPL-2.0 */
/* Copyright © 2021-2022 Intel Corporation */

/**
 * C API for RPMVersion
 */

#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

enum rpm_version_op {
    /** Less than */
    RPM_VER_LT,
    /** Less than or equal */
    RPM_VER_LE,
    /** equal */
    RPM_VER_NE,
    /** Not Equal */
    RPM_VER_EQ,
    /** Greater than or equal */
    RPM_VER_GE,
    /** Greater than */
    RPM_VER_GT,
};

/**
 * Compare two versions, with the given comparison operator
 *
 * @param ver1 The first version to compare
 * @param op  The comparison operator to use
 * @param ver2 The first version to compare
 * @return True if the comparison is successful, otherwise false
 */
bool rpm_version_compare(const char * ver1, enum rpm_version_op op, const char * ver2);

#ifdef __cplusplus
}
#endif