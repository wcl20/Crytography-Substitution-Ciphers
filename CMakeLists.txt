cmake_minimum_required(VERSION 3.0)
project(main)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(main ${SOURCES})
