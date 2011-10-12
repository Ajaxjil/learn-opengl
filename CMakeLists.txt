cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake
    ${CMAKE_MODULE_PATH})

find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(
    ${GLFW_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    )

set(CPP 
    src/main.cpp
    )
add_executable(main ${CPP})
target_link_libraries(main ${GLFW_LIBRARY} ${OPENGL_LIBRARY})
