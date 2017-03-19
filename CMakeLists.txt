cmake_minimum_required(VERSION 3.5)
project(Program)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -static-libgcc -static-libstdc++")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(SOURCE_FILES src/main.cpp)
add_executable(Program ${SOURCE_FILES})

target_link_libraries(Program pthread)
target_link_libraries(Program ${CMAKE_DL_LIBS})