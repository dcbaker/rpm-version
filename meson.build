# SPDX-license-identifier: Apache-2.0 OR GPL-2.0
# Copyright © 2022 Intel Corporation

project(
  'rpm-version',
  'cpp',
  version : '0.0.2-devel',
  meson_version : '>= 0.57',
  license : 'Apache-2.0 OR GPL-2.0',
  default_options : ['cpp_std=c++17', 'c_std=c99'],
)

inc = include_directories('include')

lib_priv = static_library(
  'rv-impl',
  'src/version.cpp',
  include_directories : inc,
)

pkg = import('pkgconfig')

lib_cpp = library(
  'rpm-version++',
  link_whole : lib_priv,
  install : true,
)

pkg.generate(
  lib_cpp,
  name : 'rpm-version-c++',
)

dep_rpm_ver_cpp = declare_dependency(
  link_with : lib_cpp,
  include_directories : inc,
)

meson.override_dependency('rpm-version-c++', dep_rpm_ver_cpp)

lib_c = library(
  'rpm-version',
  'src/capi.cpp',
  link_with : lib_priv,
  include_directories : inc,
  install : true,
)

pkg.generate(
  lib_c,
  name : 'rpm-version-c',
)

dep_rpm_ver_c = declare_dependency(
  link_with : lib_c,
  include_directories : inc,
)

meson.override_dependency('rpm-version-c', dep_rpm_ver_c)

install_headers(
  'include/rpm-version/version.h',
  'include/rpm-version/version.hpp',
  subdir : 'rpm-version',
)

if not get_option('tests').disabled()
  subdir('tests')
endif