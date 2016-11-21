#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL/glew.h"
#include "MoxieCore/stb_image.h"
#include <fstream>
#include <string>
using namespace std;

class Texture {
        public:
                Texture(const string &filename);
                void Bind(void);
                ~Texture();
        private:
                GLuint m_texture;
};

#endif
