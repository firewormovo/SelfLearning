cmake_minimum_required(VERSION 3.0)

project(complex)
message(STATUS "[PROJECT_NAME]:${PROJECT_NAME}")
message(STATUS "[PROJECT_SOURCE_DIR]:${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/src
)

# file(GLOB_REURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
# add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp)