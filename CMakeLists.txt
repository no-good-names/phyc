cmake_minimum_required(VERSION 3.28)
project(Phyc CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

# GLAD
add_subdirectory(libs/GLAD EXCLUDE_FROM_ALL)
include_directories(libs/GLAD/include ${GLFW_INCLUDE_DIRS})
include(FetchContent)
FetchContent_Declare(
        GLFW
        GIT_REPOSITORY
        GIT_TAG
)

add_executable(Phyc src/main.cpp)

target_link_libraries(Phyc PRIVATE glad glfw)
