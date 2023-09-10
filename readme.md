# Project Icoengine

## Description

This is a repo housing the icoengine project.

Right now, it's in very early development and may change to being just yet another game, with the actual engine being developed on its basis. I'm not sure about this yet.

OpenGL is responsible for graphics. I'm still learning it so the project structure is, lightly put, imperfect.

## Building

On Windows, build the project with Cmake using the VC2019 compiler. Do not forget to install required OpenGL headers and libraries (GL, GLEW, GLFW, GLAD). Make sure you have the latest glfw.lib file included in the ./build directory, otherwise the build will fail. If you lose it, download the Windows GLFW binary (x86-x64 depending on your compiler), copy the glfw3.lib from the ./lib/vc2019 and rename it to glfw.lib.

On Linux, build the project with GCC (x86-x64 depending on your compiler). If needed, install the required dependencies from the Terminal (follow any online guide).

After merging code from any branch to stable, make sure to clear cache and rebuild the project depending on your system to prevent build conflicts.

It is planned to move to cross-platform conflict-free compilation using clang or mingw.