#ifndef MESH_H
#define MESH_H

#include "GL/glew.h"
#include "glm/glm.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

#define NUM_BUFFERS 4
#define VERTEX_LIMIT 65534
// Not actually limited yet

enum MeshBuffers {
        POSITION_VB,
        TEXCOORD_VB,
        NORMAL_VB,
        INDEX_VB
};

class Mesh {
        public:
                Mesh(const string &filename);
                void Draw(const float x, const float y, const float z);
                ~Mesh();
        private:
                glm::vec3 *m_vertices;
                glm::vec3 *m_normals;
                glm::vec2 *m_texCoords;
                GLuint m_VAO;
                GLuint m_VABs[NUM_BUFFERS];
};

#endif
