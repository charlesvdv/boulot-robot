set (EXCLUDE_DIR "build/")
file(GLOB_RECURSE ALL_CXX_SOURCE_FILES *.cpp *.hpp)
foreach (TMP_PATH ${ALL_CXX_SOURCE_FILES})
    string (FIND ${TMP_PATH} ${EXCLUDE_DIR} EXCLUDE_DIR_FOUND)
    if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
        list (REMOVE_ITEM ALL_CXX_SOURCE_FILES ${TMP_PATH})
    endif ()
endforeach(TMP_PATH)

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

