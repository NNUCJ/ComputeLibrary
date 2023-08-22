cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(icl_compute)

# 设置root 
set(WORK_ROOT "/workspace/mlc/ComputeLibrary")

# 设置源文件目录
aux_source_directory(${WORK_ROOT}/src/core SRC_LIST)
aux_source_directory(${WORK_ROOT}/src/runtime SRC_LIST)
aux_source_directory(${WORK_ROOT}/src/common SRC_LIST)
aux_source_directory(${WORK_ROOT}/src/common/cpuinfo SRC_LIST)

message(${WORK_ROOT})
# message(${SRC_LIST})
# 添加头文件
include_directories(${WORK_ROOT}  
    ${WORK_ROOT}/include
    ${WORK_ROOT}/src
    ${WORK_ROOT}/support)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib) 

add_library(icl_compute SHARED ${SRC_LIST})
target_sources(icl_compute PRIVATE
              /workspace/mlc/ComputeLibrary/src/core/CPP/CPPTypes.cpp
              ${WORK_ROOT}/src/runtime/CPP/SingleThreadScheduler.cpp
              ${WORK_ROOT}/src/common/utils/LegacySupport.cpp)