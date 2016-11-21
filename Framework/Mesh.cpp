#include "MoxieCore/Mesh.h"

Mesh::Mesh(const string &filename) {
        ifstream file(filename.c_str(), ios::binary);
        if (!file.good())
                throw runtime_error("Cannot open model " + filename);

        uint32_t magic;
        uint16_t secHead;
        uint16_t secSize;

        file.read((char*)&magic, 4);
        if (magic != 0x584F4DFE)
                throw runtime_error(filename + " isn't valid Moxie");

        while (!file.eof()) {
                file.read((char*)&secHead, 2);
                file.read((char*)&secSize, 2);
                if (secSize > VERTEX_LIMIT)
                        throw runtime_error(filename + " exceeds vertex limit");
                switch(secHead) {
                        case 0xE54D:
                                m_vertices = new glm::vec3[secSize/3];
                                file.read((char*)m_vertices, secSize*4);
                                break;
                        case 0xE64D:
                                m_texCoords = new glm::vec2[secSize/3];
                                file.read((char*)m_texCoords, secSize*4);
                                break;
                        case 0xE74D:
                                m_normals = new glm::vec3[secSize/3];
                                file.read((char*)m_normals, secSize*4);
                                break;
                        case 0xE84D:
                                // Still working on this
                                break;
                        default:
                                throw runtime_error(filename + " contains invalid section headers");
                                break;
                }
        }
        file.close();

        glGenVertexArrays(1, &m_VAO);
        glGenBuffers(NUM_BUFFERS, m_VABs);

        glBindBuffer(GL_ARRAY_BUFFER, m_VABs[POSITION_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices[0])/4, m_vertices,
                        GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ARRAY_BUFFER, m_VABs[TEXCOORD_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(m_texCoords[0])/4, m_texCoords,
                        GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
        
        glBindBuffer(GL_ARRAY_BUFFER, m_VABs[NORMAL_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(m_normals[0])/4, m_normals,
                        GL_STATIC_DRAW);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindVertexArray(0);
}

void Mesh::Draw(const float x, const float y, const float z) {
        glm::vec3 pos(x, y, z);
        pos.x = x;
        pos.y = y;
        pos.z = z;

        glBindVertexArray(m_VAO);
        glDrawElementsBaseVertex(GL_TRIANGLES, sizeof(m_vertices)/4,
                        GL_FLOAT, 0, 0);
        glBindVertexArray(0);
}

Mesh::~Mesh() {
        delete[] m_vertices;
        delete[] m_texCoords;
        delete[] m_normals;
}
