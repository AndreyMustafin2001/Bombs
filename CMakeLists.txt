cmake_minimum_required(VERSION 3.10)
project(test)
add_executable(test main.cpp)
target_link_libraries(test gtest)
configure_file(input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)

