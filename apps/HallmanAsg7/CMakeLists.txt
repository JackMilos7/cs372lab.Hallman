cmake_minimum_required(VERSION 3.1)

#set the project name
project(vectTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../include)

#add the executable
add_executable(GraphTest GraphTest.cpp)
add_executable(GraphMatrixTest GraphMatrixTest.cpp)
add_executable(bacon KevinBacon.cpp)