cmake_minimum_required(VERSION 3.15)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

# 头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)

# 源文件目录
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/utils DIR_SRCS)
aux_source_directory(nc/class4 CURRENT)

add_executable(run ${DIR_SRCS} ${CURRENT} nc/lintcode_5_kth_largest_number.cpp)