cmake_minimum_required(VERSION 3.20.0)
set(CXX_STANDARD 20)
project(CppSnake VERSION 0.1.0)

file(GLOB sourceCPP "src/*.cc")

add_executable(CppSnake 
  # ${sourceCPP}
  src/main.cc
  src/gameState.cc
  src/snake.cc
  src/apple.cc
)