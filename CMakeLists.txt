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

add_subdirectory("path-planning")
add_subdirectory("robotlib")
