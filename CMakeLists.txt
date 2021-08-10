cmake_minimum_required(VERSION 3.15.2)

# set the project name and version
project(Parent_Child VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Child Child.cpp)
add_executable(Parent Parent.cpp)