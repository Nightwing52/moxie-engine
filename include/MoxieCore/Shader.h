#ifndef SHADER_H
#define SHADER_H

#include "GL/glew.h"
#include <stdexcept>
#include <fstream>
#include <string>
using namespace std;

class Shader {
        public:
                Shader(const string &filename, unsigned int type);
                void Bind(void);
                ~Shader();
        private:
                GLuint m_program;
                GLuint m_shader;
};

#endif
