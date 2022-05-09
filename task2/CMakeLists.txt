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

target_include_directories(${PROJECT_SOURCE_DIR}/B)
add_subdirectory(B)
set(EXTRA_LIBS ${EXTRA_LIBS} Mylib)
target_link_libraries(C Mylib)

set_target_properties(Mylib PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)


####

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

enable_testing()
target_include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(CTest A/index.h B/lib.h B/lib.cpp C/main_tests.cpp C/main_test.cpp )
set_target_properties(CTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
target_include_directories(CTest PUBLIC ${PROJECT_SOURCE_DIR})

target_include_directories(CTest PUBLIC ${GTEST_INCLUDE_DIRS})

target_link_libraries( CTest gtest gtest_main )
add_test( CTest google-test )
