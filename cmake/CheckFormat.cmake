set (EXCLUDE_DIR "build/")
file(GLOB_RECURSE ALL_CXX_SOURCE_FILES 
    ${PROJECT_SOURCE_DIR}/libs/*/*.hpp 
    ${PROJECT_SOURCE_DIR}/libs/*/*.cpp)

#https://gitlab.cern.ch/Caribou/peary/commit/167da6ffcaca80666f581b1d75e00771fcaeed3a
add_custom_target(
    check-format
    COMMAND ${CLANG_FORMAT} 
    -style=file 
    -output-replacements-xml
    ${ALL_CXX_SOURCE_FILES}
    | tee ${CMAKE_BINARY_DIR}/check_format_file.txt | grep -c "replacement " |
    tr -d "[:cntrl:]" && echo " replacements necessary"
    COMMAND ! grep -c "replacement "
    ${CMAKE_BINARY_DIR}/check_format_file.txt > /dev/null
)

add_custom_target(
    format-all
    COMMAND ${CLANG_FORMAT} 
    -i
    -style=file
    ${ALL_CXX_SOURCE_FILES}
    -verbose
)

