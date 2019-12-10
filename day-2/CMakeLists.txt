cmake_minimum_required(VERSION 2.6)

project(Day3)

#Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#Link runTests with what we want to test and the GTest and pthread librar/home/smedury/GitRepos/daily-coding-problem/day-2y
add_executable(executeTests tests.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
