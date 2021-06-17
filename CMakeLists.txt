cmake_minimum_required(VERSION 3.17)
project(v2.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(v2.0 main.cpp Student.cpp Student.h General.cpp General.h StudentFile.cpp StudentFile.h Test.cpp Test.h)
add_subdirectory(lib/googletest)

include_directories(lib.googletest/googletest/include)
add_executable(unit_test utest.cpp utest.cpp Student.cpp Student.h General.cpp General.h)
target_link_libraries(unit_test gtest gtest_main)