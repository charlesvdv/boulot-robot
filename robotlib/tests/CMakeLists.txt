add_executable("robotlib-test"
    test-proximity-detection.cpp
    main.cpp)

target_link_libraries("robotlib-test"
    PRIVATE "robotlib" "io-interface-raspi" Catch2::Catch2)

target_compile_features("robotlib-test" PRIVATE cxx_std_17)

add_test(NAME Robotlib COMMAND "robotlib-test")