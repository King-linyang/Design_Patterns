# cmake 版本
cmake_minimum_required(VERSION 3.26)
# c语言
project(Language_Build C)
# c语言标准
set(CMAKE_C_STANDARD 17)

# 设置源文件地址 file(GLOB/GLOB_RECURSE(递归) 变量名 要搜索的文件路径和文件类型)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
# 设置头文件地址
file(GLOB HEADER ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(singleton main.c ${SRC} ${HEADER})
