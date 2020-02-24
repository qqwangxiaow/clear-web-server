set(SRCS
    Eventloop.cc
)
include_directories(${PROJECT_SOURCE_DIR}/base/)


add_executable(clearweb ${SRCS})
target_link_libraries(clearweb base/CurrentThread.h)


add_subdirectory(test)