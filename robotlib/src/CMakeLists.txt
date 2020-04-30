add_library(robotlib
    placeholder.cpp
)

target_include_directories(robotlib 
    PUBLIC ../include 
    PRIVATE .
)

target_compile_features(robotlib PUBLIC cxx_std_17)
