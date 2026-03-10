cmake_minimum_required(VERSION 3.15)
project(gabagool C)

set(CMAKE_C_STANDARD 99)

find_package(raylib REQUIRED)

add_executable(gabagool main.c)

target_link_libraries(gabagool PRIVATE raylib)