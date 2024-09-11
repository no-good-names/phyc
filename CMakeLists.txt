cmake_minimum_required(VERSION 3.5)
project(Phyc C)

set(CMAKE_C_STANDARD 99)

include(FetchContent)

# GLAD
add_subdirectory(libs/GLAD EXCLUDE_FROM_ALL)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/libs/GLAD/include/glad/glad.h)
	message(FATAL_ERROR "GLAD not found")
endif()	

# GLFW
find_package(glfw)
if(NOT glfw_FOUND)
	include(FetchContent)
	FetchContent_Declare(
		glfw
		GIT_REPOSITORY https://github.com/glfw/glfw
	)
	FetchContent_MakeAvailable(glfw)

endif(NOT glfw_FOUND)

include_directories(libs/GLAD/include ${GLFW_INCLUDE_DIRS})

# GLOB source files
file(GLOB SOURCES "src/*.c" "src/*.h")

add_executable(Phyc ${SOURCES})

target_link_libraries(Phyc PRIVATE glad glfw)
