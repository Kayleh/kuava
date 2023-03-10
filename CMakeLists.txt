cmake_minimum_required(VERSION 3.0)
project(kuava)
file(GLOB_RECURSE kuava "src/*.cpp" "src/*.h")

add_library(${PROJECT_NAME} STATIC
        ${kuava} "../codeforce/leetcode/Java/src/temp/leetcode/editor/cn/[1590]使数组和能被 P 整除.cpp")

set(CMAKE_CXX_STANDARD 14)

#add_executable(kuava main.cpp)

message(STATUS "SRC_DIR_LIST = ${kuava}")			#打印kuava中列表信息