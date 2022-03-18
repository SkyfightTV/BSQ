cmake_minimum_required(VERSION 3.21)
project(BSQ C)

set(CMAKE_C_STANDARD 99)

add_executable(BSQ main.c bsq.h read.c)
