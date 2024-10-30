cmake_minimum_required(VERSION 2.8)
project(Minimalistic_ECS_Test)

#lib
include_directories(src)
add_library(mecs src/mecs.cpp)

#test
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
include_directories(test)
add_executable(test test/test.cpp)
link_libraries(test mecs)