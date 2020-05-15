add_library("io-interface-raspi"
    ultra_sonic_sensor.cpp
)

target_include_directories("io-interface-raspi"
    PUBLIC ../../include 
    PRIVATE .
)

target_compile_features("io-interface-raspi" PUBLIC cxx_std_17)
