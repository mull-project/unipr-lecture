cmake_minimum_required(VERSION 3.18)
project(unipr-lecture)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")

include(build-system.cmake)

add_subdirectory(example-1)
add_subdirectory(example-2)
