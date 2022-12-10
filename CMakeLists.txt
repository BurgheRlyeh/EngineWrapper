cmake_minimum_required(VERSION 3.23)
project(EngineWrapper)

set(CMAKE_CXX_STANDARD 23)

add_executable(EngineWrapper main.cpp src/engine/Engine.h src/wrapper/Wrapper.h)
