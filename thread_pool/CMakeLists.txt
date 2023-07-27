cmake_minimum_required(VERSION 3.10.0)

project(test_thread_pool)

set (CMAKE_CXX_FLAGS "--std=c++17")

file(GLOB include_dir "${PROJECT_SOURCE_DIR}/*.h")


add_executable(${PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/test_thread_pool.cpp
    ${PROJECT_SOURCE_DIR}/ttpl.cpp
    ${include_dir}
    )

