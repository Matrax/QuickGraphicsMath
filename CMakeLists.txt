#CMake version
cmake_minimum_required(VERSION 3.10)

# Set CMake property
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# QGM variables
set(LIB_NAME QGM)
set(LIB_VERSION 1.0)

# Project
project(${LIB_NAME}  
        VERSION ${LIB_VERSION} 
        LANGUAGES CXX)

# Add the interface library
add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# Matrix test
add_executable(matrix_test tests/matrix_test.cpp)
target_link_libraries(matrix_test ${LIB_NAME})

# Matrix test
add_executable(vector_test tests/vector_test.cpp)
target_link_libraries(vector_test ${LIB_NAME})