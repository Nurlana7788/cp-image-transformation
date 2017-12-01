include_directories (${CppProject_SOURCE_DIR}/headers)
add_library(
    src
        color.cpp 
        pixel.cpp
        image.cpp
        composite_image.cpp
        brightness_histogram.cpp
        scaled_image.cpp
)
