include_directories (${CppProject_SOURCE_DIR}/headers)

add_library(
    task
        task.cpp 
        task5.cpp
        task7.cpp
        task6.cpp
        task8.cpp
)
target_link_libraries(task image)
