#CMake version
cmake_minimum_required(VERSION 3.20)

# Set CMake property
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# QGM variables
set(LIB_NAME "QGM")
set(LIB_VERSION 1.0)

# Project
project(${LIB_NAME}  
        DESCRIPTION "C++17 graphics maths library"
        VERSION ${LIB_VERSION} 
        LANGUAGES CXX)

# Add the interface library
add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# Tests
if(DEFINED QGM_COMPILE_TESTS)

        # Matrix
        add_executable(matrix_test "tests/matrix_test.cpp")
        target_link_libraries(matrix_test ${LIB_NAME})

        # Vector
        add_executable(vector_test "tests/vector_test.cpp")
        target_link_libraries(vector_test ${LIB_NAME})

endif()

