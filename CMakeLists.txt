cmake_minimum_required(VERSION 4.0)
project(gameOfLife)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(gameOfLife main.cpp
        constants.h
        board.h
        board.cpp
        random.h
        boardCamera.h
        boardCamera.cpp
        pattern.h)

target_link_libraries(gameOfLife -lraylib -lGL -lm -lpthread -ldl -lrt -lX11)