cmake_minimum_required (VERSION 2.6)
project (CppProject)
# set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
# set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

subdirs (src tests)

set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories (${CppProject_SOURCE_DIR}/headers)
include_directories (${CppProject_SOURCE_DIR}/src)
link_directories (${CppProject_SOURCE_DIR}/src)

add_executable(main main.cpp)
target_link_libraries(main task)
