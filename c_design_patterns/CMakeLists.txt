# cmake 版本
cmake_minimum_required(VERSION 3.26)
# c语言
project(C_Pro_Data_Test_String C)
# c语言标准
set(CMAKE_C_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")
#set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")


# 添加子目录
add_subdirectory(c_some_test)
add_subdirectory(01_singleton)
add_subdirectory(02_prototype)
add_subdirectory(03_single_factory)
add_subdirectory(04_abstract_factory)