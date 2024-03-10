cmake_minimum_required(VERSION 3.10)
project(ABBP
        VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)

# emscripten common compile and link option, we add them for both compiler and linker.
add_compile_options(-sNODERAWFS=1 -sALLOW_MEMORY_GROWTH=1) #  -sNODERAWFS=1 use raw node file system, thus we can access local files within js code; -sALLOW_MEMORY_GROWTH our binary input file maybe too large to fit into initial memory.
add_link_options(-sNODERAWFS=1 -sALLOW_MEMORY_GROWTH=1)

set(common_dir ${CMAKE_SOURCE_DIR}/common)
set(common_sources ${common_dir}/byte_stream_reader.cpp ${common_dir}/vector_subbyte_reader.cpp)
add_library(common STATIC ${common_sources})

set(hevc_dir ${CMAKE_SOURCE_DIR}/hevc)
set(hevc_sources ${hevc_dir}/hevc_parser.cpp ${hevc_dir}/hevc_nal_unit_header.cpp ${hevc_dir}/hevc_nal_unit.cpp ${hevc_dir}/js_wrapper/hevc_wrapper.cpp)
add_library(hevc_parser STATIC ${hevc_sources})
target_include_directories(hevc_parser PUBLIC
                           ${CMAKE_SOURCE_DIR}/common)
target_include_directories(hevc_parser PUBLIC /usr/local/Cellar/emscripten/3.1.55/libexec/cache/sysroot/include)
target_link_libraries(hevc_parser common)

add_executable(parser ${CMAKE_SOURCE_DIR}/app/main.cpp)
target_include_directories(parser PRIVATE
                           ${CMAKE_SOURCE_DIR}/hevc)
target_link_libraries(parser hevc_parser)

install(TARGETS hevc_parser DESTINATION ${CMAKE_BINARY_DIR}/lib)
install(TARGETS parser DESTINATION  ${CMAKE_BINARY_DIR}/bin)
install(FILES ${CMAKE_SOURCE_DIR}/hevc/hevc_parser.h ${CMAKE_SOURCE_DIR}/common/abbp.h DESTINATION ${CMAKE_BINARY_DIR}/include)