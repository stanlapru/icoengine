cmake_minimum_required(VERSION 3.0.0)
project(icoengine_game_engine VERSION 0.0.1)
cmake_policy(SET CMP0072 NEW)
find_package(OpenGL REQUIRED)
add_executable(icoengine_game_engine 
src/main.cpp 
src/glad.h 
src/glad.c 
src/khrplatform.h)
target_link_libraries(icoengine_game_engine 
    glfw 
    OpenGL::GL
)