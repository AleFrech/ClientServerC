cmake_minimum_required(VERSION 3.3)
project(ClientServerC__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp User.cpp User.h FileManager.h Validations.cpp Validations.h)
add_executable(ClientServerC__ ${SOURCE_FILES})