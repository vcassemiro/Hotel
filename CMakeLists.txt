# Require CMAKE 3.5 
cmake_minimum_required(VERSION 3.5)

# Project name
project(Hotel)

# Build for C++20 if we can
set(CMAKE_CXX_STANDARD 20)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX")

# Any source files in this directory
set(SOURCE_FILES src/main/main.cpp)

set(LIBRARY_NAME Include)

include(FetchContent)

# Where any include files are
include_directories(src/lib)

# Subdirectories to build
add_subdirectory(src/lib)
add_subdirectory(src/tests)



# Name of executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link
target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME})
