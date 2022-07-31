cmake_minimum_required(VERSION 3.21)
project(Task0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(./googletest)
set(LIBRARIES
        gtest
        pthread)

add_executable(Task0 Box.cpp Container.cpp Box.h Container.h Tests.cpp main.cpp)
target_link_libraries(Task0 ${LIBRARIES})
