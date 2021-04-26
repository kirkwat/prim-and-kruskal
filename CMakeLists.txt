cmake_minimum_required(VERSION 3.16)
project(s21_pa04_kwatson)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_DEBUG “-O3”)

add_executable(s21_pa04_kwatson src/main.cpp src/Edge.cpp src/Edge.h src/Graph.cpp src/Graph.h src/UnionFind.cpp src/UnionFind.h src/IndexedPriorityQueue.cpp src/IndexedPriorityQueue.h src/MST_Algos.cpp src/MST_Algos.h)
