#include <iostream>
#include "./glad.h"
#include <GLFW/glfw3.h>


int main(int, char**){
    GLFWwindow* window;

    if (!glfwInit()){
        return -1;
    }

    window = glfwCreateWindow(640, 480, "Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Could not load OpenGL." << std::endl;
        glfwTerminate();
        return -1;
    }

    glClearColor(0.25f, 0.25f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    std::cout << "Hello World!" << std::endl;

    return 0;
}