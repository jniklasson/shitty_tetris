cmake_minimum_required(VERSION 3.10)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)
# set the project name
project(shitty_tetris)

#SDL
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

# add the executable
file(GLOB SOURCES src/*.cpp)
add_executable(shitty_tetris ${SOURCES})
target_include_directories(shitty_tetris PUBLIC
                          "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(shitty_tetris ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})