# Project ArmCompute_Self
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)


# Project IclCompute
# set(CMAKE_C_COMPILER gcc)
# set(CMAKE_CXX_COMPILER g++)


list(APPEND CMAKE_MESSAGE_CONTEXT ArmCompute_Self)
project(
        ArmCompute_Self
        VERSION 0.0.1
        DESCRIPTION 
        "ACL test branch by Paul Cheng" 
        LANGUAGES C CXX ASM)


set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Options.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Version.cmake)

# Require at least gcc/g++ 11) CMAKE_CXX_COMPILER_VERSION OR
# if(CMAKE_C_COMPILER_VERSION VERSION_LESS 10.2 OR CMAKE_CXX_COMPILER_VERSION
#                                                  VERSION_LESS 10.2)
#   message(
#     FATAL_ERROR "gcc and g++ version => 10.2 is required for building project!")
# endif()

#------------------------------------------------------------------------------------
# Configuration

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -gdwarf-2 -DARM_COMPUTE_ASSERTS_ENABLED")
# Default to Release Build
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE
      "Release"
      CACHE
        STRING
        "Choose build type, available options are: Debug, Release, RelWithDebInfo"
        FORCE)
endif()

# ---------------------------------------------------------------------
# Information

message(STATUS "Arm Compute Library ${PROJECT_VERSION}")

# ---------------------------------------------------------------------
# Compile options and features

set(COMMON_CXX_FLAGS
    -Wall
    -DARCH_ARM
    -Wextra
    -Wdisabled-optimization
    -Wformat=2
    -Winit-self
    -Wstrict-overflow=2
    -Wswitch-default
    -Woverloaded-virtual
    -Wformat-security
    -Wctor-dtor-privacy
    -Wsign-promo
    -Weffc++
    -Wno-overlength-strings
    -Wno-ignored-attributes
    -Wlogical-op
    -Wnoexcept
    -Wstrict-null-sentinel
    -Wno-misleading-indentation
    -O3)

# Disable note popups on compiler ABI changes
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options("-Wno-psabi")
endif()


# ---------------------------------------------------
# Core Library
add_library(arm_compute "")
# target_compile_options(arm_compute PRIVATE "-march=${COMMON_CXX_FLAGS}")
# target_compile_definitions(arm_compute PRIVATE ARM_COMPUTE_ENABLE_BF16)

target_include_directories(
    arm_compute
    PUBLIC  $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            ${CMAKE_CURRENT_SOURCE_DIR}/support
            ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE src)

target_compile_options(arm_compute PUBLIC ${COMMON_CXX_FLAGS})

add_library(ArmCompute::Core ALIAS arm_compute)

add_subdirectory(src)
# message(${BASIC_COMPONENT_TEST})
if(BASIC_COMPONENT_TEST)
    add_subdirectory(basic_component_test)
    # CUSTOM TEST FOR Acl commponent 
    foreach(test_name ${CUSTOM_TEST_NAMES})
        add_executable(${test_name} "basic_component_test/${test_name}.cpp")
        # target_compile_options(${test_name} PRIVATE ${COMMON_CXX_FLAGS})
        set_target_properties(
                ${test_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                    "bin")
        target_link_libraries(${test_name} PUBLIC arm_compute)           
    endforeach(test_name)
endif() # BASIC_COMPONENT_TEST


#  cmake -DCMAKE_BUILD_TYPE="Debug" -DBASIC_COMPONENT_TEST=ON ..
    

