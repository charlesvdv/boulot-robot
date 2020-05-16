add_executable("path-planning-test"
    test_obstacle_circle.cpp
    test_obstacle_rectangle.cpp
    test_quadtree.cpp
    test_map.cpp
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