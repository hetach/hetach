Hetach uses [CMake](http://www.cmake.org/) as a build system. There are two basic steps to integrate Hetach into Your project

## Build library

If You use build system other than CMake (or Your system do not support external projects) build Hetach library. Execute following commands:

```sh
mkdir build
cd build
cmake [-DHETACH_BUILD_TESTS=ON] ..
make
```

when library is built, add include path and link library in Your build system

## CMake external project

Create directory `ext/hetach` and put there `CMakeLists.txt` file with content:

```
cmake_minimum_required(VERSION 2.8)
project(hetach_builder CXX)
include(ExternalProject)

ExternalProject_Add(hetach
    GIT_REPOSITORY https://github.com/hetach/hetach.git
    GIT_TAG master
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(hetach source_dir)
set(HETACH_INCLUDE_DIRS ${source_dir}/include PARENT_SCOPE)

ExternalProject_Get_Property(hetach binary_dir)
set(HETACH_LIBS_DIR ${binary_dir} PARENT_SCOPE)
```

Add in Your `CMakeLists.txt` file below lines:

```
add_subdirectory(ext/hetach)

include_directories(${HETACH_INCLUDE_DIRS})

add_dependencies(<project_name> hetach)

target_link_libraries(<project_name> -L${HETACH_LIBS_DIR} hetach${CMAKE_SHARED_LIBRARY_SUFFIX})
```
