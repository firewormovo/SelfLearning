
cmake_minimum_required(VERSION 3.0)
project(coding)
file(GLOB_RECURSE EXTRA_FILES */*)
add_custom_target(${PROJECT_NAME}_OTHER_FILES ALL WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} SOURCES ${EXTRA_FILES})

# 获取需要被编译成可执行文件的所有cpp文件
file(GLOB_RECURSE code_sources "./*learn.cpp")
# 遍历每一个需要被编译的cpp文件
foreach(code_src ${code_sources})
    get_filename_component(mexecutable ${code_src} NAME_WE)
    add_executable(${mexecutable} ${code_src})
endforeach()