add_library("visualization" 
    point.cpp
    rectangle.cpp 
    circle.cpp
    line.cpp
    xml-node.cpp
    renderer.cpp
    svg-renderer.cpp
)

target_include_directories("visualization" 
    PUBLIC ../include 
    PRIVATE .
)

target_compile_features("visualization" PUBLIC cxx_std_17)



