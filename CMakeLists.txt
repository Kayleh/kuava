cmake_minimum_required(VERSION 3.0)
project(kuava)
file(GLOB_RECURSE kuava "src/*.cpp" "src/*.h")

add_library(${PROJECT_NAME} STATIC
        ${kuava})

set(CMAKE_CXX_STANDARD 14)

#add_executable(kuava main.cpp)
