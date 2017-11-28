cmake_minimum_required (VERSION 2.6)
project (CppProject)
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

subdirs (src tests)

