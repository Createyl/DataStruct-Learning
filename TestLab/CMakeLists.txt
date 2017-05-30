cmake_minimum_required(VERSION 3.7)
project(TestLab)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp createMatrix.cpp 1.cpp)
add_executable(TestLab ${SOURCE_FILES})