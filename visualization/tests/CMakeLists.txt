add_executable("visualization-test"
    main.cpp)

target_link_libraries("visualization-test"
    PRIVATE "visualization" Catch2::Catch2)

target_compile_features("visualization-test" PRIVATE cxx_std_17)

add_test(NAME VISUALIZATION COMMAND "visualization-test")