cmake_minimum_required(VERSION 3.13)
project(cgraph C CXX)

set(CMAKE_C_STANDARD 11)

add_library(cgraph SHARED src/graph.c src/graph.h)

find_package(GTest)
if (GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(UnitTest tests/tests.cpp tests/graph_test.cpp)
    target_include_directories(UnitTest PRIVATE src)
    target_link_libraries(UnitTest ${GTEST_LIBRARIES} pthread cgraph)
endif()