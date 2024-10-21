# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the header files directory
include_directories(include)

# Include the utils directory for headers
include_directories(src/utils)

# Add the executable
add_executable(myexe
    src/main.cpp
    src/utils/utils.cpp
)
