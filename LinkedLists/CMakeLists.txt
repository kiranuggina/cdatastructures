cmake_minimum_required(VERSION 2.10)

project("list")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/out)

file(GLOB src *.c *.h)

add_executable(list ${src})