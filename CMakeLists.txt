cmake_minimum_required(VERSION 3.19)

# 拿到当前文件所在目录的名字
get_filename_component(ProjectID ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# 如果目录中包含空格替换成"_"
string(REPLACE " " "_" ProjectID ${ProjectID})

project(${ProjectID} C)

set(CMAKE_C_STANDARD 11)

# 获取目录下所有的.C,.h文件存入files里
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# 遍历files把它们添加成可执行程序
foreach (file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file} src/template/动态规划/背包/完全背包.cpp)
endforeach ()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # 生成compile_commands.json文件



# 设置输出目录为/mnt/d/project/kayleh/kuava/out/mybin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/mnt/d/project/kayleh/kuava/out/mybi")

 
