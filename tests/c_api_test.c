// SPDX-License-Identifier: Apache-2.0
// Copyright © 2022-2024 Intel Corporation

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rpm-version/version.h"

static enum rpm_version_op op_from_str(const char * raw) {
    if (strcmp(raw, ">=") == 0) {
        return RPM_VER_GE;
    } else if (strcmp(raw, ">") == 0) {
        return RPM_VER_GT;
    } else if (strcmp(raw, "==") == 0) {
        return RPM_VER_EQ;
    } else if (strcmp(raw, "!=") == 0) {
        return RPM_VER_NE;
    } else if (strcmp(raw, "<=") == 0) {
        return RPM_VER_LE;
    } else if (strcmp(raw, "<") == 0) {
        return RPM_VER_LT;
    } else {
        abort();
    }
}

int main(int argc, char * argv[]) {
    assert(argc == 5);
    unsigned i = 1;
    const char * left = argv[i++];
    enum rpm_version_op op = op_from_str(argv[i++]);
    const char * right = argv[i++];
    bool expected = strcmp(argv[i++], "0") == 0;

    bool result = rpm_version_compare(left, op, right);

    return result == expected ? 0 : 1;
}