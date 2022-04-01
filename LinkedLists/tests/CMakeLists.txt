include_directories("${PROJECT_SOURCE_DIR}/list")

file(GLOB tests "${PROJECT_SOURCE_DIR}/tests/*.cpp")

set(CMAKE_CXX_STANDARD 11)

foreach(file ${tests})
  set(name)
  get_filename_component(name ${file} NAME_WE)
  add_executable("${name}_tests" ${file})
  target_link_libraries("${name}_tests" PUBLIC 
  linkedlist
  gtest
  gmock
  gtest_main)
  add_test(NAME ${name} COMMAND "${name}_tests")
endforeach()
