cmake_minimum_required(VERSION 3.7)
project(BTTREE_test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BT.h)
add_executable(BTTREE_test ${SOURCE_FILES})