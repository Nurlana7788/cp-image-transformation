include_directories (${CppProject_SOURCE_DIR}/headers)
include_directories (${CppProject_SOURCE_DIR}/src)
link_directories (${CppProject_SOURCE_DIR}/src)

add_executable(composite_image composite_image.cpp)
target_link_libraries(composite_image image)

add_executable(histogram brightness_histogram.cpp)
target_link_libraries(histogram image)

add_executable(reflection reflection.cpp)
target_link_libraries(reflection image)

add_executable(task5 task5.cpp)
target_link_libraries(task5 image)

add_executable(task7 task7.cpp)
target_link_libraries(task7 image)
