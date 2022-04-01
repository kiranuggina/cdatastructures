project("algos")

file(GLOB src *.c *.h)

include_directories("${PROJECT_SOURCE_DIR}/algos")

add_library(${PROJECT_NAME} ${src})