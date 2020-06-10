cmake_minimum_required(VERSION 3.16)
project(sourcecode)

message("sourcecode with googlemock test")

# 添加googletest
include_directories( ./sort/ ./third_library/googletest/googlemock/include ./third_library/googletest/googletest/include )
link_directories(./third_library/googletest/lib)

set(CMAKE_CXX_STANDARD 20)

add_executable(sourcecode main.cpp test/alltest.h sort/quicksort.h sort/sort.h)
target_link_libraries (sourcecode gtestd gmockd)