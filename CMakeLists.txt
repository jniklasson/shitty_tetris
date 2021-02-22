cmake_minimum_required(VERSION 3.10)

# set the project name
project(shitty_tetris)

#SDL
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# add the executable
add_executable(shitty_tetris src/main.cpp)
target_include_directories(shitty_tetris PUBLIC
                          "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(shitty_tetris ${SDL2_LIBRARIES})