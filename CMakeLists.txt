cmake_minimum_required(VERSION 3.16)

project(boulot-robot
    VERSION 0.1
    DESCRIPTION "Control software for the eurobot 2021"
    LANGUAGES CXX)

include(CTest)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.12.1
)
FetchContent_MakeAvailable(Catch2)

FetchContent_Declare(
    bilkemodules
    GIT_REPOSITORY https://github.com/bilke/cmake-modules
    GIT_TAG 0503702f2ef733aa8f6a0c2015db89b085c5ac57
)
FetchContent_GetProperties(bilkemodules)
if (NOT bilkemodules_POPULATED)
    FetchContent_Populate(bilkemodules)

    list(APPEND CMAKE_MODULE_PATH "${bilkemodules_SOURCE_DIR}")
endif()

option(CODE_COVERAGE "Enable code coverage" OFF)
if (CODE_COVERAGE)
    set(CMAKE_BUILD_TYPE "Debug")
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "Looking for clang-tidy")
find_program(CLANG_TIDY NAMES clang-tidy)

if (CLANG_TIDY)
    message(STATUS "Looking for clang-tidy - found ${CLANG_TIDY}")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY}")
else()
    message(STATUS "Looking for clang-tidy - not found")
endif()

message(STATUS "Looking for clang-format")
find_program(CLANG_FORMAT NAMES clang-format)

if (CLANG_FORMAT)
    message(STATUS "Looking for clang-format - found ${CLANG_FORMAT}")
    include(.cmake/check-format.cmake)
else()
    message(STATUS "Looking for clang-format - not found")
endif()

add_subdirectory("path-planning")
add_subdirectory("robotlib")
add_subdirectory("io-interface")
add_subdirectory("visualization")