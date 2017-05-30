cmake_minimum_required(VERSION 3.7)
project(GraphTheory_0530)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES library.c library.h)
add_library(GraphTheory_0530 ${SOURCE_FILES})