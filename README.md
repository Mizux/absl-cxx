Github-CI:<br>
[![Build Status][github_linux_status]][github_linux_link]
[![Build Status][github_macos_status]][github_macos_link]
[![Build Status][github_windows_status]][github_windows_link]<br>

[![Build Status][github_amd64_docker_status]][github_amd64_docker_link]
[![Build Status][github_arm64_docker_status]][github_arm64_docker_link]
[![Build Status][github_riscv64_docker_status]][github_riscv64_docker_link]<br>

[![Build Status][github_arm_toolchain_status]][github_arm_toolchain_link]
[![Build Status][github_aarch64_toolchain_status]][github_aarch64_toolchain_link]
[![Build Status][github_mips_toolchain_status]][github_mips_toolchain_link]
[![Build Status][github_mips64_toolchain_status]][github_mips64_toolchain_link]
[![Build Status][github_powerpc_toolchain_status]][github_powerpc_toolchain_link]
[![Build Status][github_riscv64_toolchain_status]][github_riscv64_toolchain_link]<br>

[github_linux_status]: https://github.com/Mizux/absl-cxx/actions/workflows/amd64_linux.yml/badge.svg
[github_linux_link]: https://github.com/Mizux/absl-cxx/actions/workflows/amd64_linux.yml
[github_macos_status]: https://github.com/Mizux/absl-cxx/actions/workflows/amd64_macos.yml/badge.svg
[github_macos_link]: https://github.com/Mizux/absl-cxx/actions/workflows/amd64_macos.yml
[github_windows_status]: https://github.com/Mizux/absl-cxx/actions/workflows/amd64_windows.yml/badge.svg
[github_windows_link]: https://github.com/Mizux/absl-cxx/actions/workflows/amd64_windows.yml

[github_amd64_docker_status]: https://github.com/Mizux/absl-cxx/actions/workflows/amd64_docker.yml/badge.svg
[github_amd64_docker_link]: https://github.com/Mizux/absl-cxx/actions/workflows/amd64_docker.yml
[github_arm64_docker_status]: https://github.com/Mizux/absl-cxx/actions/workflows/arm64_docker.yml/badge.svg
[github_arm64_docker_link]: https://github.com/Mizux/absl-cxx/actions/workflows/arm64_docker.yml
[github_riscv64_docker_status]: https://github.com/Mizux/absl-cxx/actions/workflows/riscv64_docker.yml/badge.svg
[github_riscv64_docker_link]: https://github.com/Mizux/absl-cxx/actions/workflows/riscv64_docker.yml

[github_arm_toolchain_status]: https://github.com/Mizux/absl-cxx/actions/workflows/arm_toolchain.yml/badge.svg
[github_arm_toolchain_link]: https://github.com/Mizux/absl-cxx/actions/workflows/arm_toolchain.yml
[github_aarch64_toolchain_status]: https://github.com/Mizux/absl-cxx/actions/workflows/aarch64_toolchain.yml/badge.svg
[github_aarch64_toolchain_link]: https://github.com/Mizux/absl-cxx/actions/workflows/aarch64_toolchain.yml
[github_mips_toolchain_status]: https://github.com/Mizux/absl-cxx/actions/workflows/mips_toolchain.yml/badge.svg
[github_mips_toolchain_link]: https://github.com/Mizux/absl-cxx/actions/workflows/mips_toolchain.yml
[github_mips64_toolchain_status]: https://github.com/Mizux/absl-cxx/actions/workflows/mips64_toolchain.yml/badge.svg
[github_mips64_toolchain_link]: https://github.com/Mizux/absl-cxx/actions/workflows/mips64_toolchain.yml
[github_powerpc_toolchain_status]: https://github.com/Mizux/absl-cxx/actions/workflows/powerpc_toolchain.yml/badge.svg
[github_powerpc_toolchain_link]: https://github.com/Mizux/absl-cxx/actions/workflows/powerpc_toolchain.yml
[github_riscv64_toolchain_status]: https://github.com/Mizux/absl-cxx/actions/workflows/riscv64_toolchain.yml/badge.svg
[github_riscv64_toolchain_link]: https://github.com/Mizux/absl-cxx/actions/workflows/riscv64_toolchain.yml

# Introduction
<nav for="project"> |
<a href="#requirement">Requirement</a> |
<a href="#codemap">Codemap</a> |
<a href="#build">Build</a> |
<a href="ci/README.md">CI</a> |
<a href="#appendices">Appendices</a> |
<a href="#license">License</a> |
</nav>

This is an example of how to create a Modern [CMake](https://cmake.org/) C++ Project.

This project should run on GNU/Linux, MacOS and Windows.

## Requirement
You'll need:

* "CMake >= 3.16".

## Codemap
The project layout is as follow:

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

### Misc
Image has been generated using [plantuml](http://plantuml.com/):
```bash
plantuml -Tsvg docs/{file}.dot
```
So you can find the dot source files in [ci/docs](ci/docs).

## License
Apache 2. See the LICENSE file for details.

## Disclaimer
This is not an official Google product, it is just code that happens to be
owned by Google.

