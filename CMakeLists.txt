cmake_minimum_required(VERSION 3.0.0)
project(clearweb)
set(library_SOURCES
    src/Eventloop.cc
    src/base/CurrentThread.h
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(clearweblib STATIC ${library_SOURCES})

add_executable(${PROJECT_NAME} ./src/test/Eventloop_test1.cc)
target_link_libraries(clearweb clearweblib)
