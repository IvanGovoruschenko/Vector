cmake_minimum_required(VERSION 3.23)
project(Vector C)

set(CMAKE_C_STANDARD 17)

add_executable(Vector main.c vector.c vector.h)
