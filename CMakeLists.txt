cmake_minimum_required(VERSION 3.17)
project(untitled8)

enable_testing()
add_subdirectory(googletest)
include_directories(googletest/googletest/include)

add_executable(untitled8 main.cpp ${SOURCE_FILES})
add_executable(tests tests.cpp ${SOURCE_FILES})
target_link_libraries(tests gtest)
