cmake_minimum_required(VERSION 3.8)

project(typhoon)

# Setting the C++ standard directly
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add the executable
add_executable(typhoon main.cpp
    src/Bastet/Engine.cpp src/Bastet/Game.cpp src/Bastet/Screen.cpp
    src/Bastet/Well.cpp src/Bastet/Block.cpp src/Bastet/BlockPosition.cpp
    
    src/Silver/Water.cpp src/Silver/Ship.cpp)

# Add link libraries
target_link_libraries(typhoon PRIVATE ncursesw)

# Add source groups in project
# source_group("src" FILES ${SRC})

# Some useful commands
# ctags -R --exclude='.git/' --exclude='build/' '/usr/include/c++/13/' './'
# git diff -U0 HEAD^ | ./tools/clang-format-diff.py -p1 -i
