cmake_minimum_required(VERSION 3.0.0)
project(clearweb)
set(library_SOURCES
    src/Eventloop.cc
)
add_library(clearweb STATIC ${library_SOURCES})
add_executable(${PROJECT_NAME} ./src/test/Eventloop_test1.cc)