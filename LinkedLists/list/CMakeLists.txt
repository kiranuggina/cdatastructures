project("linkedlist")

file(GLOB src *.c *.h)

include_directories("${PROJECT_SOURCE_DIR}/list")

add_library(${PROJECT_NAME} ${src})