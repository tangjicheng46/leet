cmake_minimum_required(VERSION 3.12)
project(cpp)
set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)

add_executable(cpp_exec main.cpp)
target_link_libraries(cpp_exec Boost::boost)
