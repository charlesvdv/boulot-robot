# Disable clang-tidy for test
set(CMAKE_CXX_CLANG_TIDY "")

add_executable("path-planning-test"
    test-obstacle-circle.cpp
    test-obstacle-rectangle.cpp
    test-quadtree.cpp
    test-map.cpp
    main.cpp)

target_link_libraries("path-planning-test"
    PRIVATE "path-planning" Catch2::Catch2)

# A little hack to include normally private header file 
# so we can still test some implementation details.
target_include_directories("path-planning-test" 
    PRIVATE ../src
)

target_compile_features("path-planning-test" PRIVATE cxx_std_17)

add_test(NAME PathPlanning COMMAND "path-planning-test")