#CMake version
cmake_minimum_required(VERSION 3.20)

# options
option(BUILD_TESTS "Build the tests" OFF)

# Project
project(QuickGraphicsMath
        DESCRIPTION "C++17 graphics math library"
        VERSION 1.0
        LANGUAGES CXX)

# Add the interface library
add_library(QuickGraphicsMath INTERFACE)

# include directories
target_include_directories(QuickGraphicsMath INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/includes")

# Tests
if(BUILD_TESTS)

        # Matrix
        add_executable(qgm_matrix_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/matrix_test.cpp")
        target_link_libraries(qgm_matrix_test QuickGraphicsMath)

        # Vector
        add_executable(qgm_vector_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/vector_test.cpp")
        target_link_libraries(qgm_vector_test QuickGraphicsMath)
        
        # Math
        add_executable(qgm_math_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/math_test.cpp")
        target_link_libraries(qgm_math_test QuickGraphicsMath)

        # Random
        add_executable(qgm_random_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/random_test.cpp")
        target_link_libraries(qgm_random_test QuickGraphicsMath)

        # Mesh
        add_executable(qgm_mesh_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/mesh_test.cpp")
        target_link_libraries(qgm_mesh_test QuickGraphicsMath)

endif()

