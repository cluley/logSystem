cmake_minimum_required(VERSION 3.22.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(LogSystem)

add_executable(LogSystem main.cpp logCommand.h logCommand.cpp observe.h observe.cpp)