cmake_minimum_required(VERSION 3.15)
project(cgraph C)

set(CMAKE_C_STANDARD 11)

add_library(cgraph SHARED cgraph.c cgraph.h)
