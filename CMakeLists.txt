cmake_minimum_required(VERSION 3.10)
project(ABBP
        VERSION 0.1)
set(CMAKE_CXX_STANDARD 11)
add_library(common STATIC
            ${CMAKE_SOURCE_DIR}/common/byte_stream_reader.cpp)

add_library(hevc_parser STATIC
            ${CMAKE_SOURCE_DIR}/hevc/hevc_parser.cpp)
target_include_directories(hevc_parser PUBLIC
                           ${CMAKE_SOURCE_DIR}/common)
target_link_libraries(hevc_parser common)

add_executable(parser ${CMAKE_SOURCE_DIR}/app/main.cpp)
target_include_directories(parser PRIVATE
                           ${CMAKE_SOURCE_DIR}/hevc)
target_link_libraries(parser hevc_parser)

install(TARGETS hevc_parser DESTINATION ${CMAKE_BINARY_DIR}/lib)
install(TARGETS parser DESTINATION  ${CMAKE_BINARY_DIR}/bin)
install(FILES ${CMAKE_SOURCE_DIR}/hevc/hevc_parser.h ${CMAKE_SOURCE_DIR}/common/abbp.h DESTINATION ${CMAKE_BINARY_DIR}/include)