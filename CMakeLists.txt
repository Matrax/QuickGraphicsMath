#CMake version
cmake_minimum_required(VERSION 3.10)

# Project
project(QuickGraphicsMath VERSION 1.0 LANGUAGES CXX)

# Set CMake property
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add test executable
add_executable(QuickGraphicsMath test/main.cpp)