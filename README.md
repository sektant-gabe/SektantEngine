# Sektant Engine 

![C++](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17%2F20%2F23-blue)
![License](https://img.shields.io/github/license/franneck94/CppProjectTemplate)

- Library and executable code separated in distinct folders.
- Use of modern CMake for building and compiling.
- External libraries:
  - All graphical and imgui related libs via Git submodules:
    - GLFW, Imgui and Implot
  - General purpose libraries via CMake FetchContent:
    - [JSON](https://github.com/nlohmann/json), [cxxopts](https://github.com/jarro2783/cxxopts) and [fmt](https://github.com/fmtlib/fmt)
- Continuous integration testing with Github Actions and [pre-commit](https://pre-commit.com/)
- Code documentation with [Doxygen](https://doxygen.nl/) and [Github Pages](https://franneck94.github.io/CppProjectTemplate/)
- Tooling: Clang-Format, Cmake-Format, Clang-tidy, Sanitizers

## Structure

``` text
├── CMakeLists.txt
├── sandbox
│   ├── CMakesLists.txt
│   └── main.cc
├── cmake
│   └── cmake modules
├── docs
│   ├── Doxyfile
│   └── html/
├── external
│   ├── CMakesLists.txt
│   ├── ...
├── modules
│   ├── CMakesLists.txt
└── ─── SKT/...
```

Library code goes into [modules/](modules/), engine editor program code in [sandbox/](sandbox).

## Software Requirements

- CMake 3.21+
- GNU Makefile
- Doxygen
- VCPKG
- MSVC 2017 (or higher), G++9 (or higher), Clang++9 (or higher)

## Building

First, clone this repo and do the preliminary work:

```shell
git clone --recursive https://github.com/sektant-gabe/SektantEngine
mkdir build
```

- Sandbox Executable

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --target sandbox
cd sandbox
./sandbox
```

- Documentation

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target docs
```
