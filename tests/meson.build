# SPDX-license-identifier: Apache-2.0 OR GPL-2.0
# Copyright © 2022 Intel Corporation

inc_src = include_directories('../src')

dep_gtest = dependency(
  'gtest_main',
  required : get_option('tests'),
  disabler : true,
  allow_fallback : true,
)

test(
  'version_cpp',
  executable(
    'version_test',
    'version_test.cpp',
    dependencies : dep_gtest,
    link_with : lib_cpp,
    include_directories : [inc, inc_src],
  )
)

if get_option('c-bindings')
  enable_c_api_test = true
  c_api_link_language = 'c'
  if get_option('default_library') == 'static'
    # If we've statically linked then we have to use the C++ linker :/
    c_api_link_language = 'cpp'
  else
    enable_c_api_test = add_languages('c', required : false, native : false)
  endif

  if enable_c_api_test
    if add_languages('c', required : false, native : false)
      c_api = executable(
        'c_api_test',
        'c_api_test.c',
        link_language : c_api_link_language,
        dependencies : dep_rpm_ver_c,
      )

      cases = [
        ['4', '<', '2', '1'],
        ['1', '<', '2', '0'],
        ['4', '>', '2', '0'],
        ['1', '>', '2', '1'],
      ]

      foreach case : cases
        test(
          '@0@@1@@2@ is @3@'.format(case[0], case[1], case[2], case[3] == '0' ? 'true' : 'false'),
          c_api,
          args : case,
          suite : 'C API'
        )
      endforeach
    endif
  endif
endif
