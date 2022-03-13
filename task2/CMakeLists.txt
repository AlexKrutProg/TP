cmake_minimum_required(VERSION 3.0)

project(C)

add_custom_command( 
  OUTPUT ${PROJECT_SOURCE_DIR}/A/index.h
  COMMAND python ${PROJECT_SOURCE_DIR}/A/preparing.py  ${PROJECT_SOURCE_DIR}/A/index.h
  DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
  COMMENT "Generating array"
)

add_custom_target( RunGenerator DEPENDS ${PROJECT_SOURCE_DIR}/A/index.h COMMENT "Checking if re-generation is required" )
add_executable(C ${PROJECT_SOURCE_DIR}/C/main.cpp)
add_dependencies(C RunGenerator )
set_target_properties(C PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

target_include_directories(C PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(CTest ${PROJECT_SOURCE_DIR}/C/main_test.cpp)
set_target_properties(CTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


include_directories(${PROJECT_SOURCE_DIR}/B)
add_subdirectory(B)
set(EXTRA_LIBS ${EXTRA_LIBS} Mylib)
target_link_libraries(C Mylib)

set_target_properties(Mylib PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

