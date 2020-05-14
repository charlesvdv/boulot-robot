add_library(robotlib
    proximity_handler.cpp
)

target_link_libraries(robotlib
    PRIVATE "io-interface")

target_include_directories(robotlib 
    PUBLIC ../include 
    PRIVATE .
)

target_compile_features(robotlib PUBLIC cxx_std_17)
