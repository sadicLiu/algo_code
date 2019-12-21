cmake_minimum_required(VERSION 3.15)
project(code_cpp)

set(CMAKE_CXX_STANDARD 11)

# 头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)

# 源文件目录
aux_source_directory(utils DIR_SRCS)

add_executable(code_cpp ${DIR_SRCS} nc/class3/03_81.cpp)