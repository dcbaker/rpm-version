// SPDX-License-Identifier: Apache-2.0 OR GPL-2.0
// Copyright © 2022-2024 Intel Corporation

#include "private.hpp"
#include "rpm-version/version.h"
#include "rpm-version/version.hpp"

namespace {

RPMVersion::Operator from_c(rpm_version_op op) {
    switch (op) {
        case RPM_VER_EQ:
            return RPMVersion::Operator::eq;
        case RPM_VER_NE:
            return RPMVersion::Operator::ne;
        case RPM_VER_LT:
            return RPMVersion::Operator::lt;
        case RPM_VER_LE:
            return RPMVersion::Operator::le;
        case RPM_VER_GE:
            return RPMVersion::Operator::ge;
        case RPM_VER_GT:
            return RPMVersion::Operator::gt;
        default:
            RPM_VERSION_UNREACHABLE("Unsupported operator");
    }
}

} // namespace

extern "C" {

bool rpm_version_compare(const char * ver1, enum rpm_version_op op, const char * ver2) {
    return RPMVersion::compare(ver1, from_c(op), ver2);
}
}