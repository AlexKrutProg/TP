cmake_minimum_required(VERSION 3.0)

project(GG)

add_custom_command( 
  OUTPUT ${PROJECT_SOURCE_DIR}/C/A/index.h
  COMMAND python ${PROJECT_SOURCE_DIR}/C/A/preparing.py  ${PROJECT_SOURCE_DIR}/C/A/index.h
  DEPENDS ${PROJECT_SOURCE_DIR}/C/A/preparing.py
  COMMENT "Generating array"
)

add_custom_target( RunGenerator DEPENDS ${PROJECT_SOURCE_DIR}/C/A/index.h COMMENT "Checking if re-generation is required" )

#add_custom_command(TARGET cerating_folder PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_NAME}/bin)
add_executable(C ${PROJECT_SOURCE_DIR}/C/main.cpp)
add_dependencies(C RunGenerator )
set_target_properties(C PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
