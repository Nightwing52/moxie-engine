#include "MoxieCore/Shader.h"

Shader::Shader(const string &filename, unsigned int type) {
        ifstream file;
        file.open(filename.c_str(), ios::in);
        if (!file.good())
                throw runtime_error("Cannot load shader " + filename);

        string text((istreambuf_iterator<char>(file)),
                        istreambuf_iterator<char>());

        m_program = glCreateProgram();
        m_shader = glCreateShader(type);

        if (m_shader == 0)
                throw runtime_error("Cannot compile shader " + filename);
        const char *c_str = text.c_str();
        int lengths = text.length();
        glShaderSource(m_shader, 1, &c_str, &lengths);
        glCompileShader(m_shader);

        GLint success;
        glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE)
                throw runtime_error("Cannot compile shader " + filename);

        glAttachShader(m_program, m_shader);
        glBindAttribLocation(m_program, 0, "position");
        glBindAttribLocation(m_program, 1, "texCoord");
        glBindAttribLocation(m_program, 2, "normal");

        glLinkProgram(m_program);
        glGetProgramiv(m_program, GL_LINK_STATUS, &success);
        if (success == GL_FALSE)
                throw runtime_error("Cannot link shader " + filename);

        glValidateProgram(m_program);
        glGetProgramiv(m_program, GL_LINK_STATUS, &success);
        if (success == GL_FALSE)
                throw runtime_error("Not a valid shader program " + filename);
}

void Shader::Bind(void) {
        glUseProgram(m_program);
}

Shader::~Shader() {
        glDetachShader(m_program, m_shader);
        glDeleteShader(m_shader);
        glDeleteProgram(m_program);
}
