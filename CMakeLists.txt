cmake_minimum_required(VERSION 3.16)

project(eurobot-2021
    VERSION 0.1
    DESCRIPTION "Control software for the eurobot 2021"
    LANGUAGES CXX)

add_subdirectory("path-planning")
add_subdirectory("robotlib")
