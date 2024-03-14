# rpm-version
A version comparison library conforming to RPM's rules.


## What is it?

It's a library for doing RPM compatible version compatible with the rules that
RPM uses. It's implemented in C++ 17, but provides a stable C API as well.


## Why?

Because in build system land it turns out that you need this sort of stuff, a lot.


## What's the status?

The API is *not* guaranteed stable, but I don't forsee any backwards
incompatible changes.


## How do I use it?

rpm-version provides pkg-config files, so you can install it, and add the
pkg-config files to your `$PKG_CONFIG_PATH`, then use whatever `pkg-config`
facility goes along with your build system, looking for either `rpm-version-c`
or `rpm-version-c++`, depnding on whether you want the C or C++ API.

If you're using meson, it also supports being used as a subproject.

Add the following wrap files to your `subprojects` directory:

```ini
[wrap-file]
directory = rpm-version-0.0.2

source_url = https://github.com/dcbaker/rpm-version/archive/v0.0.2.tar.gz
source_filename = rpm-version-0.0.2.tar.gz
source_hash = 8ca93adf977603219bde766f5f9f752c4880d870d18e8df167e2d2ba283656b6

[provide]
rpm-version-c = dep_rpm_ver_c
rpm-version-c++ = dep_rpm_ver_cpp
```

You can then just add `dependency('rpm-version-c++')` (or `rpm-version-c`), to
your meson.build and use as normal. you may want to use
`dependency('rpm-version-c++', default_options : ['default_library=static'])`,
which will instruct meson to build rpm-version as a static library instead of a
dynamic one.

## How do I use the C API?

```C
#include <rpm-version/version.h>

int main(void) {
    return rpm_version_compare("1.2.3", RPM_VER_LT, "4.5");
 }
 ```


## How about the C++ API?

```C++
#include <rpm-version/version.hpp>

int main() {
    return PRMVersion::compare("1.2.3", RPMVersion::Operator::lt, "4.5");
}
```