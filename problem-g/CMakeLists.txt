cmake_minimum_required(VERSION 3.20)
project(problem-g)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

file(GLOB TARGET_H ./*.h)
file(GLOB TARGET_SRC ./*.cpp)

add_executable(problem-g
        ${TARGET_SRC}
        ${TARGET_H}
        main.cpp)
