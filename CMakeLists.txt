cmake_minimum_required(VERSION 3.21)
project(Ex4_c C)

set(CMAKE_C_STANDARD 99)

add_executable(Ex4_c Graph.h Graph.c main.c Node.c Node.h Edge.c Edge.h)
