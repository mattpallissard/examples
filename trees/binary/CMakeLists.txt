set(CMAKE_GENERATOR "Ninja")
cmake_minimum_required(VERSION 3.12.4)
project(binary_tree VERSION 0.0.1 LANGUAGES C)

include_directories( include )
add_executable(sample array.c sample.c)
