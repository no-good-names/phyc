cmake_minimum_required(VERSION 3.5)
project(Phyc C)

set(CMAKE_C_STANDARD 99)

find_package(glfw3 REQUIRED) # installed with local package manager

# GLAD
add_subdirectory(libs/GLAD EXCLUDE_FROM_ALL)
include_directories(libs/GLAD/include ${GLFW_INCLUDE_DIRS})

# GLOB source files
file(GLOB SOURCES "src/*.c" "src/*.h")

add_executable(Phyc ${SOURCES})

target_link_libraries(Phyc PRIVATE glad glfw)
