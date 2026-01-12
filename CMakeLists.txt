cmake_minimum_required(VERSION 4.0)
project(mcli C)

set(CMAKE_C_STANDARD 99)

add_executable(mcli_dev main.c)

add_subdirectory(mcli)
target_link_libraries(mcli_dev mcli)
