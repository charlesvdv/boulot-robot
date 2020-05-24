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
    GIT_TAG        v2.12.1
)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "Looking for clang-tidy")
find_program(CLANG_TIDY NAMES clang-tidy)

if (CLANG_TIDY)
    message(STATUS "Looking for clang-tidy - found ${CLANG_TIDY}")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY}")
else()
    message(STATUS "Looking for clang-tidy - not found")
endif()

add_subdirectory("path-planning")
add_subdirectory("robotlib")
add_subdirectory("io-interface")
add_subdirectory("visualization")
