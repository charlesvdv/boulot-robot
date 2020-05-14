add_library("io-interface"
    ultra_sonic_sensor.cpp
)

target_include_directories("io-interface"
    PUBLIC ../include 
    PRIVATE .
)

target_compile_features("io-interface" PUBLIC cxx_std_17)
