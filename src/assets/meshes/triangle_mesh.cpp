#include "triangle_mesh.h"
#include "../../glad.h"
#include <GLFW/glfw3.h>

TriangleMesh::TriangleMesh() {
    
    // std::vector<float> data = {
    //     // Normalized Device Coordinates: -1 is left, 1 is right - Vertices/Color
    //     -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, // 3xBottom left, 3xColor
    //      1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // 3xBottom right, 3xColor
    //     -1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f  // 3xTop left, 3xColor
    // };

    std::vector<float> positions = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f
    };

    std::vector<int> colorIndices = {
        0, 1, 2
    };

    // Vertex is a collection of properties/attributes required to draw an object.
    vertex_count = 3;

    // VAO = Vertex Array Object
    // VAO records the VBO's and its attribs
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    VBOs.resize(2);

    // VBO = Vertex Buffer Object - binary data + attrib pointers (how to interpret data)
    glGenBuffers(2, &VBOs[0]); // Gets shipped to the GPU, passive ref to integer

    // Position
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]); // Put VBO on Arraybuffer
    glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), positions.data(), GL_STATIC_DRAW); // Send target, number of bytes we send, pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, (void*)0); // Attrib number (pos=0), number of numbers in attrib, data format, indicating normalization reqt, stride in bytes (24=6 floats * 4 bytes), offset to the start of attrib
    glEnableVertexAttribArray(0); // Do not confuse AttribArray with ArrayAttrib, check documentation (OGL versioning issue)

    // Color
    glGenBuffers(1, &VBOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]); // Put VBO on Arraybuffer
    glBufferData(GL_ARRAY_BUFFER, colorIndices.size() * sizeof(int), colorIndices.data(), GL_STATIC_DRAW);
    glVertexAttribIPointer(1, 1, GL_INT, 4, (void*)0); // Color attrib = 1
    glEnableVertexAttribArray(1);

}

void TriangleMesh::draw() {
    glBindVertexArray(VAO); // This recalls data from VBO's
    glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}

TriangleMesh::~TriangleMesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(VBOs.size(), VBOs.data());
}