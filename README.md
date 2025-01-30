Github-CI:
| OS \ Build system | Bazel | CMake |
|:------- | :---: | :---: |
| Linux (`amd64`) | [![Build Status][amd64_linux_bazel_status]][amd64_linux_bazel_link] | [![Build Status][amd64_linux_cmake_status]][amd64_linux_cmake_link] |
| MacOS (`amd64`) | [![Build Status][amd64_macos_bazel_status]][amd64_macos_bazel_link] | [![Build Status][amd64_macos_cmake_status]][amd64_macos_cmake_link] |
| MacOS (`arm64`) | [![Build Status][arm64_macos_bazel_status]][arm64_macos_bazel_link] | [![Build Status][arm64_macos_cmake_status]][arm64_macos_cmake_link] |
| Windows (`amd64`) | [![Build Status][amd64_windows_bazel_status]][amd64_windows_bazel_link] | [![Build Status][amd64_windows_cmake_status]][amd64_windows_cmake_link] |
| Docker (`amd64`)  | [![Build Status][amd64_docker_bazel_status]][amd64_docker_bazel_link] | [![Build Status][amd64_docker_cmake_status]][amd64_docker_cmake_link] |
| Docker (`arm64`)  | NA | [![Build Status][arm64_docker_cmake_status]][arm64_docker_cmake_link] |
| Docker (`riscv64`)  | NA | [![Build Status][riscv64_docker_cmake_status]][riscv64_docker_cmake_link] |

[amd64_linux_bazel_status]: ./../../actions/workflows/amd64_linux_bazel.yml/badge.svg
[amd64_linux_bazel_link]: ./../../actions/workflows/amd64_linux_bazel.yml
[amd64_macos_bazel_status]: ./../../actions/workflows/amd64_macos_bazel.yml/badge.svg
[amd64_macos_bazel_link]: ./../../actions/workflows/amd64_macos_bazel.yml
[arm64_macos_bazel_status]: ./../../actions/workflows/arm64_macos_bazel.yml/badge.svg
[arm64_macos_bazel_link]: ./../../actions/workflows/arm64_macos_bazel.yml
[amd64_windows_bazel_status]: ./../../actions/workflows/amd64_windows_bazel.yml/badge.svg
[amd64_windows_bazel_link]: ./../../actions/workflows/amd64_windows_bazel.yml
[amd64_docker_bazel_status]: ./../../actions/workflows/amd64_docker_bazel.yml/badge.svg
[amd64_docker_bazel_link]: ./../../actions/workflows/amd64_docker_bazel.yml

[amd64_linux_cmake_status]: ./../../actions/workflows/amd64_linux_cmake.yml/badge.svg
[amd64_linux_cmake_link]: ./../../actions/workflows/amd64_linux_cmake.yml
[amd64_macos_cmake_status]: ./../../actions/workflows/amd64_macos_cmake.yml/badge.svg
[amd64_macos_cmake_link]: ./../../actions/workflows/amd64_macos_cmake.yml
[arm64_macos_cmake_status]: ./../../actions/workflows/arm64_macos_cmake.yml/badge.svg
[arm64_macos_cmake_link]: ./../../actions/workflows/arm64_macos_cmake.yml
[amd64_windows_cmake_status]: ./../../actions/workflows/amd64_windows_cmake.yml/badge.svg
[amd64_windows_cmake_link]: ./../../actions/workflows/amd64_windows_cmake.yml
[amd64_docker_cmake_status]: ./../../actions/workflows/amd64_docker_cmake.yml/badge.svg
[amd64_docker_cmake_link]: ./../../actions/workflows/amd64_docker_cmake.yml
[arm64_docker_cmake_status]: ./../../actions/workflows/arm64_docker_cmake.yml/badge.svg
[arm64_docker_cmake_link]: ./../../actions/workflows/arm64_docker_cmake.yml
[riscv64_docker_cmake_status]: ./../../actions/workflows/riscv64_docker_cmake.yml/badge.svg
[riscv64_docker_cmake_link]: ./../../actions/workflows/riscv64_docker_cmake.yml

CMake toolchain:<br>
[![Build Status][arm_toolchain_status]][arm_toolchain_link]
[![Build Status][aarch64_toolchain_status]][aarch64_toolchain_link]
[![Build Status][mips_toolchain_status]][mips_toolchain_link]
[![Build Status][mips64_toolchain_status]][mips64_toolchain_link]
[![Build Status][powerpc_toolchain_status]][powerpc_toolchain_link]
[![Build Status][powerpc64_toolchain_status]][powerpc64_toolchain_link]
[![Build Status][riscv64_toolchain_status]][riscv64_toolchain_link]<br>

[arm_toolchain_status]: ./../../actions/workflows/arm_toolchain.yml/badge.svg
[arm_toolchain_link]: ./../../actions/workflows/arm_toolchain.yml
[aarch64_toolchain_status]: ./../../actions/workflows/aarch64_toolchain.yml/badge.svg
[aarch64_toolchain_link]: ./../../actions/workflows/aarch64_toolchain.yml
[mips_toolchain_status]: ./../../actions/workflows/mips_toolchain.yml/badge.svg
[mips_toolchain_link]: ./../../actions/workflows/mips_toolchain.yml
[mips64_toolchain_status]: ./../../actions/workflows/mips64_toolchain.yml/badge.svg
[mips64_toolchain_link]: ./../../actions/workflows/mips64_toolchain.yml
[powerpc_toolchain_status]: ./../../actions/workflows/powerpc_toolchain.yml/badge.svg
[powerpc_toolchain_link]: ./../../actions/workflows/powerpc_toolchain.yml
[powerpc64_toolchain_status]: ./../../actions/workflows/powerpc64_toolchain.yml/badge.svg
[powerpc64_toolchain_link]: ./../../actions/workflows/powerpc64_toolchain.yml
[riscv64_toolchain_status]: ./../../actions/workflows/riscv64_toolchain.yml/badge.svg
[riscv64_toolchain_link]: ./../../actions/workflows/riscv64_toolchain.yml

# Introduction

<nav for="project"> |
<a href="#requirement">Requirement</a> |
<a href="#codemap">Codemap</a> |
<a href="#dependencies">Dependencies</a> |
<a href="#build">Build</a> |
<a href="bazel/README.md">Bazel CI</a> |
<a href="cmake/README.md">CMake CI</a> |
<a href="#appendices">Appendices</a> |
<a href="#license">License</a> |
</nav>

This is an example of how to create a Modern [CMake](https://cmake.org/) C++ Project.

This project should run on GNU/Linux, MacOS and Windows.

note: A Bazel support is also provided as comparison

## Requirement

You'll need:

* "Bazel >= 7.0".
* "CMake >= 3.25".

## Codemap

The project layout is as follow:

* [WORKSPACE](WORKSPACE) Top-level for [Bazel](https://bazel.build) based build.
* [CMakeLists.txt](CMakeLists.txt) Top-level for [CMake](https://cmake.org/cmake/help/latest/) based build.
* [cmake](cmake) Subsidiary CMake files.

* [ci](ci) Root directory for continuous integration.

* [Foo](Foo) Root directory for `Foo` library.
  * [CMakeLists.txt](Foo/CMakeLists.txt) for `Foo`.
  * [include](Foo/include) public folder.
    * [foo](Foo/include/foo)
      * [Foo.hpp](Foo/include/foo/Foo.hpp)
  * [src](Foo/src) private folder.
    * [src/Foo.cpp](Foo/src/Foo.cpp)

## Build

To build the C++ project, as usual:
```sh
cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

To build this example you should use:

```sh
bazel build -c opt //...
```

## Running Tests

To build this example you should use:

```sh
bazel test -c opt --test_output=errors --nocache_test_results //...
```

## CI Setup

Please take a look at [.github/workflows](.github/workflows) to find the configuration file for each jobs.

To install *bazel* on each hosted runner, follow these links:
ref: https://docs.github.com/en/actions/using-github-hosted-runners/customizing-github-hosted-runners#installing-software-on-windows-runners

* Linux (Ubuntu latest LTS) -> `apt-get install bazel`<br>
  ref: https://docs.bazel.build/versions/main/install-ubuntu.html<br>
  (as of 06/2021 Ubuntu 20.04 LTS is still not supported according to the doc...)
* MacOS -> `brew install bazel`<br>
  ref: https://formulae.brew.sh/formula/bazel#default
* Windows -> `choco install bazel`<br>
  ref: https://community.chocolatey.org/packages/bazel/

## Appendices

Few links on the subject...

### Resources

Project layout:

* The Pitchfork Layout Revision 1 (cxx-pflR1)

Bazel:

* https://docs.bazel.build/versions

### Misc

Image has been generated using [plantuml](http://plantuml.com/):

```bash
plantuml -Tsvg docs/{file}.dot
```
So you can find the dot source files in [docs](docs).

## License

Apache 2. See the LICENSE file for details.

## Disclaimer

This is not an official Google product, it is just code that happens to be
owned by Google.
