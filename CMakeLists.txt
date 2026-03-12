cmake_minimum_required(VERSION 3.15)
project(gabagool C)

set(CMAKE_C_STANDARD 99)

if(WIN32)
    add_subdirectory(raylib)
else()
    find_package(raylib REQUIRED)
endif()

add_executable(gabagool main.c)

target_link_libraries(gabagool PRIVATE raylib)