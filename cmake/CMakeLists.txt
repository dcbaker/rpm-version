# SPDX-License-Identifier: Apache-2.0 OR GPL-2.0
# Copyright © 2024 Intel Corporation

# This CMake implementation is meant to provide enough to be used
# with FetchContent, not as a full implementation of a build system.
# This is to help projects using CMake to use rpm-version more easily
# Meson is the build system that is supported for doing system-wide
# installs

cmake_minimum_required(VERSION 3.22)

project(
    rpm-version
    LANGUAGES CXX
    VERSION 0.4.0
)

add_library(
    rpm_version_priv
    OBJECT
    ../src/version.cpp
)
target_include_directories(rpm_version_priv PRIVATE ../src)
target_include_directories(rpm_version_priv PUBLIC ../include)

add_library(rpm_version_cpp)
target_link_libraries(rpm_version_cpp PRIVATE rpm_version_priv)
set_target_properties(rpm_version_cpp PROPERTIES
                      VERSION ${CMAKE_PROJECT_VERSION}
                      SOVERSION 0
                      OUTPUT_NAME rpm-version-c++)
