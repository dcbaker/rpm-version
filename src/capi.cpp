// SPDX-license-identifier: Apache-2.0 OR GPL-2.0
// Copyright © 2022 Intel Corporation

#include "rpm-version/version.h"
#include "rpm-version/version.hpp"

namespace {

RPMVersion::Operator from_c(rpm_version_op op) {
    switch (op) {
        case RPM_VER_EQ:
            return RPMVersion::Operator::EQ;
        case RPM_VER_NE:
            return RPMVersion::Operator::NE;
        case RPM_VER_LT:
            return RPMVersion::Operator::LT;
        case RPM_VER_LE:
            return RPMVersion::Operator::LE;
        case RPM_VER_GE:
            return RPMVersion::Operator::GE;
        case RPM_VER_GT:
            return RPMVersion::Operator::GT;
        default:
            /* Should not be possible to reach here */
            abort();
    }
}

} // namespace

extern "C" {

bool rpm_version_compare(const char * ver1, enum rpm_version_op op, const char * ver2) {
    return RPMVersion::compare(ver1, from_c(op), ver2);
}
}