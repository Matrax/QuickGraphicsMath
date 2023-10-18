#CMake version
cmake_minimum_required(VERSION 3.8)

# options
option(BUILD_TESTS "Build the tests" OFF)

# QuickGraphicsMath variables
set(QGM_LIB_NAME "QuickGraphicsMath")
set(QGM_LIB_VERSION 1.0)
set(QGM_INCLUDES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes")
set(QGM_MATRIX_TESTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/matrix_test.cpp")
set(QGM_VECTOR_TESTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/vector_test.cpp")

# Project
project(${QGM_LIB_NAME}  
        DESCRIPTION "C++17 graphics maths library"
        VERSION ${QGM_LIB_VERSION} 
        LANGUAGES CXX)

# Add the interface library
add_library(${QGM_LIB_NAME} INTERFACE)

# include directories
target_include_directories(${QGM_LIB_NAME} INTERFACE ${QGM_INCLUDES_DIR})

# Tests
if(BUILD_TESTS)

        # Matrix
        add_executable(qgm_matrix_test ${QGM_MATRIX_TESTS})
        target_link_libraries(qgm_matrix_test ${QGM_LIB_NAME})

        # Vector
        add_executable(qgm_vector_test ${QGM_VECTOR_TESTS})
        target_link_libraries(qgm_vector_test ${QGM_LIB_NAME})
        
endif()

