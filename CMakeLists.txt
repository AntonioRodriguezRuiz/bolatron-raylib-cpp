cmake_minimum_required(VERSION 3.10)
project(RaylibProject)

set(CMAKE_CXX_STANDARD 17)

# Find Raylib
find_package(raylib REQUIRED)

# Copy resources
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

# Add executable and link Raylib
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
add_executable(game ${SOURCES})
target_link_libraries(game raylib)

