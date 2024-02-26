cmake_minimum_required(VERSION 3.10)
project(ABBP
        VERSION 0.1)
add_library(hevc_parser STATIC
            ${CMAKE_SOURCE_DIR}/hevc/hevc_parser.c)
target_include_directories(hevc_parser PRIVATE
                           ${CMAKE_SOURCE_DIR}/common)
install(TARGETS hevc_parser DESTINATION ${CMAKE_BINARY_DIR}/lib)
install(FILES ${CMAKE_SOURCE_DIR}/hevc/hevc_parser.h ${CMAKE_SOURCE_DIR}/common/abbp.h DESTINATION ${CMAKE_BINARY_DIR}/include)