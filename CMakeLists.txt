cmake_minimum_required(VERSION 2.8)
project(Minimalistic_ECS_Test)


#test
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
include_directories(include test)
add_executable(test test/test.cpp)
link_libraries(test mecs)