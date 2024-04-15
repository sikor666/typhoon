cmake_minimum_required(VERSION 3.8)

project(typhoon)

# Setting the C++ standard directly
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Create files lists
file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.*")

# Add the executable
add_executable(typhoon main.cpp ${SRC})

# Add source groups in project
source_group("src" FILES ${SRC})

