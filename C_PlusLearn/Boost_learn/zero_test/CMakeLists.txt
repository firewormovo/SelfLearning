cmake_minimum_required(VERSION 3.0)

project(test_boost)

find_package(Boost REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
