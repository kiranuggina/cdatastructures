cmake_minimum_required(VERSION 2.10)

project("sa")

##
### Test definitions ###
##

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(tests)

##
### Source definitions ###
##

file(GLOB src *.c *.h)

include_directories("${PROJECT_SOURCE_DIR}/algos")

add_subdirectory(algos)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/out)

add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} algos)
