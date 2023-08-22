cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(custom_test)

set(WORK_ROOT /workspace/mlc/ComputeLibrary)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

SET(CMAKE_BUILD_TYPE "Debug")

set(CUSTOM_TESTS 
    test_types.cpp
    test_Tensor.cpp)

foreach(CUSTOM_TEST ${CUSTOM_TESTS})
    get_filename_component(CUSTOM_TEST_NAME ${CUSTOM_TEST} NAME_WE)
    
    include_directories(${WORK_ROOT}  
    ${WORK_ROOT}/include
    ${WORK_ROOT}/src
    ${WORK_ROOT}/support)

    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/test_example)
    # 添加可执行程序
    add_executable(${CUSTOM_TEST_NAME} ${CUSTOM_TEST})
    target_link_libraries(${CUSTOM_TEST_NAME} /workspace/mlc/ComputeLibrary/custom_test/cpp/build_so/lib/libicl_compute.so)
    
endforeach(CUSTOM_TEST)
