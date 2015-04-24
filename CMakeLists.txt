cmake_minimum_required(VERSION 3.1)
project(facebook)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    linkedlist.cpp)

add_executable(facebook ${SOURCE_FILES} btree.h btree.cpp)