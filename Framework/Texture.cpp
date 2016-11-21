#include "MoxieCore/Texture.h"

Texture::Texture(const string &filename) {
        ifstream file(filename.c_str());
        if (!file.good())
                throw runtime_error("Cannot open " + filename);

        int width;
        int height;
        int numCpts;
        unsigned char *data = stbi_load(filename.c_str(), &width, &height,
                        &numCpts, 4);
        file.close();

        if (data == NULL)
                throw runtime_error("Failed to load texture " + filename);
        
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                        GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
}

void Texture::Bind(void) {
        glBindTexture(GL_TEXTURE_2D, m_texture);
}

Texture::~Texture() {
        glDeleteTextures(1, &m_texture);
}
