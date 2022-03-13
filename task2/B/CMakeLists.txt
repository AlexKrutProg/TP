cmake_minimum_required(VERSION 3.0)

add_library(B SHARED lib.cpp)
#install(TARGETS B DESTINATION ${PROJECT_SOURCE_DIR}/lib)
#install(FILES lib.h DESTINATION ${PROJECT_SOURCE_DIR}/include)
