#include "config.h"
#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "./assets/meshes/triangle_mesh.h"
//#include "./objparser.h"

unsigned int make_shader(const std::string& vertex_filepath, const std::string& frag_filepath);
unsigned int make_module(const std::string& filepath, unsigned int module_type);

unsigned int make_shader(const std::string& vertex_filepath, const std::string& frag_filepath){
    std::vector<unsigned int> modules;
    modules.push_back(make_module(vertex_filepath, GL_VERTEX_SHADER));
    modules.push_back(make_module(frag_filepath, GL_FRAGMENT_SHADER));

    unsigned int shader = glCreateProgram();

    for (unsigned int shaderModule : modules){
        glAttachShader(shader, shaderModule);
    }

    glLinkProgram(shader);

    int success;
    glGetShaderiv(shader, GL_LINK_STATUS, &success);

    if (!success){
        char errorlog[1024];
        glGetShaderInfoLog(shader, 1024, NULL, errorlog);
        std::cout << "[ICOENGINE] Couldn't link shader:\n" << errorlog << std::endl;
    }

    for (unsigned int shaderModule : modules) {
        glDeleteShader(shaderModule);
    }

    return shader;
}

unsigned int make_module(const std::string& filepath, unsigned int module_type){
    std::ifstream file;
    std::stringstream bufferedlines;
    std::string line;

    file.open(filepath);
    while (std::getline(file, line)){
        bufferedlines << line << "\n";
    }

    std::string shaderSource = bufferedlines.str();
    const char* shaderSrc = shaderSource.c_str();
    bufferedlines.str("");
    file.close();

    unsigned int shaderModule = glCreateShader(module_type);
    glShaderSource(shaderModule, 1, &shaderSrc, NULL);
    glCompileShader(shaderModule);
    
    int success;
    glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &success);

    if (!success){
        char errorlog[1024];
        glGetShaderInfoLog(shaderModule, 1024, NULL, errorlog);
        std::cout << "[ICOENGINE] Couldn't compile shader module:\n" << errorlog << std::endl;
    }

    return shaderModule;
}

int main(int, char**){

    GLFWwindow* window;

    if (!glfwInit()){
        std::cout << "Could not initialize GLFW." << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(640, 480, "Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Could not load OpenGL." << std::endl;
        glfwTerminate();
        return -1;
    }

    glClearColor(0.25f, 0.0f, 0.0f, 1.0f);
    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0,0,w,h);

    TriangleMesh* triangle = new TriangleMesh();

    unsigned int shader = make_shader(
        "../src/assets/shaders/vertex.c",
        "../src/assets/shaders/fragment.c"
    );

    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shader);
        triangle->draw();
        glfwSwapBuffers(window);
    }

    return 0;
}
