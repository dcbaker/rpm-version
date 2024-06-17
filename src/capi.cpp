// SPDX-license-identifier: Apache-2.0 OR GPL-2.0
// Copyright © 2022 Intel Corporation

#include "rpm-version/version.h"
#include "rpm-version/version.hpp"

#include <stdexcept>
#include <iostream>

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
            /* Should not be possible to reach here */
            abort();
    }
}

} // namespace

extern "C" {

bool rpm_version_compare(const char * ver1, enum rpm_version_op op, const char * ver2) {
    try {
        return RPMVersion::compare(ver1, from_c(op), ver2);
    } catch (std::invalid_argument & e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        abort();
    }
}
}
