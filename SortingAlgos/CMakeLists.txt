cmake_minimum_required(VERSION 2.10)

project("sa")

file(GLOB src *.c *.h)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/out)

add_executable(sa ${src})
