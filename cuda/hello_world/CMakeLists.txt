# CMakeLists.txt for G4CU project
project(test_cuda_project)
# required cmake version
cmake_minimum_required(VERSION 3.10)
# packages
find_package(CUDA)
# 设置使用cuda语言
enable_language(CUDA)
if(NOT DEFINED CMAKE_CUDA_STANDARD)
    set(CMAKE_CUDA_STANDARD 11)
    set(CMAKE_CUDA_STANDARD_REQUIRED ON)
endif()
# 设置使用本地硬件的架构
cuda_select_nvcc_arch_flags(ARCH_FLAGS) 
# 获取所有工程文件
file(GLOB FILES ${PROJECT_SOURCE_DIR}/*.cu)
foreach(target_file ${FILES})
    string(REGEX REPLACE "^[\/A-Za-z0-9_-]+\/\|.cu" "" current_file ${target_file})
    add_executable(${current_file} ${target_file})
endforeach()
