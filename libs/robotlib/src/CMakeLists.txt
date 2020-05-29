add_library(robotlib
    proximity-handler.cpp
)

target_link_libraries(robotlib
    PRIVATE "io-interface-raspi")

target_include_directories(robotlib 
    PUBLIC ../include 
    PRIVATE .
)

target_compile_features(robotlib PUBLIC cxx_std_17)
