cmake_minimum_required(VERSION 3.10.0)

project(test_thread)

include_directories(
    include
)

add_executable(test_thread main.cpp src/data_recv.cpp)

target_link_libraries(test_thread -lpthread)