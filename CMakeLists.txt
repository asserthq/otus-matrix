cmake_minimum_required(VERSION 3.23)
project(matrix)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(matrix src/sparse_matrix.h src/main.cpp)

find_package(GTest REQUIRED)
add_executable(matrix_test test/sparse_matrix_test.cpp)
target_include_directories(matrix_test PRIVATE src)
target_link_libraries(matrix_test GTest::gtest)

enable_testing()
add_test(tests matrix_test)
