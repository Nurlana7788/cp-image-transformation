include_directories (${CppProject_SOURCE_DIR}/headers)
include_directories (${CppProject_SOURCE_DIR}/src)
link_directories (${CppProject_SOURCE_DIR}/src)

add_executable(composite_image composite_image_test.cpp)
target_link_libraries(composite_image src)

add_executable(histogram brightness_histogram_test.cpp)
target_link_libraries(histogram src)
