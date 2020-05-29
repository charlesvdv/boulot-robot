add_library("path-planning" 
    point.cpp
    obstacle.cpp
    obstacle-rectangle.cpp
    obstacle-circle.cpp
    rectangle.cpp
    quadtree.cpp
    map.cpp
    map-impl.cpp
)

target_include_directories("path-planning" 
    PUBLIC ../include 
    PRIVATE .
)

target_compile_features("path-planning" PUBLIC cxx_std_17)