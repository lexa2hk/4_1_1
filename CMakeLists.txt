cmake_minimum_required(VERSION 3.20)
project(4_1_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(4_1_1 main.cpp cl_application.cpp cl_application.h cl_base.cpp cl_base.h child.h)
