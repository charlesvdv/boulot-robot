add_executable("path-planning-test"
    test_obstacle_circle.cpp
    test_obstacle_rectangle.cpp
    main.cpp)

target_link_libraries("path-planning-test"
    PRIVATE "path-planning" Catch2::Catch2)

target_compile_features("path-planning-test" PRIVATE cxx_std_17)

add_test(NAME PathPlanning COMMAND "path-planning-test")