cmake_minimum_required(VERSION 3.0)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
set(CMAKE_C_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-gcc)

project(SimpleLibrary)

include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)

install(TARGETS Main DESTINATION bin)
install(TARGETS MainLib DESTINATION bin)
install(TARGETS include/buffer.h DESTINATION lib)
