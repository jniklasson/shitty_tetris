cmake_minimum_required(VERSION 3.10)

# set the project name
project(shitty_tetris)

# add the executable
add_executable(shitty_tetris src/main.cpp)
target_include_directories(shitty_tetris PUBLIC
                          "${PROJECT_SOURCE_DIR}/include")