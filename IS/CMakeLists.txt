# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp board.cpp board.h Space.cpp Space.h playerHuman.cpp playerHuman.h playerComputer.cpp playerComputer.h ply.cpp ply.h Node.cpp Node.h Tree.cpp Tree.h)