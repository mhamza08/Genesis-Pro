cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(mylib VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the library target
add_library(mylib STATIC mylib.cpp)

# Include the directory for the header files
target_include_directories(mylib PUBLIC ${PROJECT_SOURCE_DIR})

# Add the executable that links with the library
add_executable(main main.cpp)

# Link the executable with the library
target_link_libraries(main PRIVATE mylib)
