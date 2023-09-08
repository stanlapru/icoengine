cmake_minimum_required(VERSION 3.5.0)
project(icoengine_game_engine VERSION 0.0.1)
cmake_policy(SET CMP0072 NEW)
find_package(OpenGL REQUIRED)
add_executable(icoengine_game_engine 
src/main.cpp 
src/glad.h 
src/glad.c 
src/config.h 
src/khrplatform.h)
src/khrplatform.h
)
target_include_directories(icoengine_game_engine
    PRIVATE
    include/
)
include_directories(icoengine_game_engine
    PRIVATE
    include/)

target_link_libraries(icoengine_game_engine 
    glfw 
    OpenGL::GL
)