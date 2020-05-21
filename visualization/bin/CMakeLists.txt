add_executable("svg-example"
    svg-example.cpp)

target_link_libraries("svg-example"
    PRIVATE "visualization")

target_compile_features("svg-example" PRIVATE cxx_std_17)
