cmake_minimum_required(VERSION 3.16)

project(Mylib VERSION 1.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC}

target_sources(${PROJECT_NAME} PRIVATE src/lib.cpp)
