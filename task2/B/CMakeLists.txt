cmake_minimum_required(VERSION 3.0)

project(Mylib)

add_library(${PROJECT_NAME} SHARED src/lib.cpp)
#install(TARGETS Mylib DESTINATION lib)
#install(FILES lib.h DESTINATION include)
