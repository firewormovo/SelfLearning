cmake_minimum_required(VERSION 3.10.0)

project(factory_learn)

file(GLOB_RECURSE project_files "${PROJECT_SOURCE_DIR}/*factory.cpp")

foreach(file ${project_files})
    message(STATUS "file_name : ${file}")
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" TARGET ${file})
    add_executable(${TARGET} ${file})
endforeach()
