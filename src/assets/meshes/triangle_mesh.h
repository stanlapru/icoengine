#include "../../config.h"

class TriangleMesh {
public:
TriangleMesh();
void draw();
~TriangleMesh();

private:
unsigned int VAO, vertex_count; // Buffer = unsigned int
std::vector<unsigned int> VBOs; 
};