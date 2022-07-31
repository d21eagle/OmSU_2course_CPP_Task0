cmake_minimum_required(VERSION 3.21)
project(Task2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task2 main.cpp RingBuffer.h RingBuffer.cpp Iterator.h Iterator.cpp)
