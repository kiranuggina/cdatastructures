cmake_minimum_required(VERSION 2.10)

project("sa")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/out)

add_executable(sa sortingalgos.c)
