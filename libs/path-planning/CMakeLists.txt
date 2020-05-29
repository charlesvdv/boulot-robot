cmake_minimum_required(VERSION 3.16)

add_subdirectory(src)

if(BUILD_TESTING) 
    add_subdirectory(tests)
endif()