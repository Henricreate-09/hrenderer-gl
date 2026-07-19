#include "Shader.hpp"

Shader::Shader(const String &name) {
    this->m_pathVert = name + ".vert";
    this->m_pathFrag = name + ".frag";


    unsigned int vert, frag;
    String vertTemp = File::ReadAsset(this->m_pathVert);
    String fragTemp = File::ReadAsset(this->m_pathFrag);

    const char *vertShaderCode = vertTemp.c_str();
    const char *fragShaderCode = fragTemp.c_str();

    size_t infologLength = 512;
    int statusSuccess = 0;
    char infolog[infologLength];


    vert = glCreateShader(GL_VERTEX_SHADER);
    frag = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vert, 1, &vertShaderCode, NULL);
    glShaderSource(frag, 1, &fragShaderCode, NULL);

    
    // SHADER COMPILATION
    glCompileShader(vert);
    glGetShaderiv(vert, GL_COMPILE_STATUS, &statusSuccess);
    if (!statusSuccess) {
        glGetShaderInfoLog(vert, infologLength, NULL, infolog);
        Debug::LogError("Vertex shader failed to compile:\n\t" + String(infolog));
    }

    glCompileShader(frag);
    glGetShaderiv(frag, GL_COMPILE_STATUS, &statusSuccess);
    if (!statusSuccess) {
        glGetShaderInfoLog(frag, infologLength, NULL, infolog);
        Debug::LogError("Fragment shader failed to compile:\n\t" + String(infolog));
    }


    this->m_shaderProgram = glCreateProgram();
    glAttachShader(this->m_shaderProgram, vert);
    glAttachShader(this->m_shaderProgram, frag);
    glLinkProgram(this->m_shaderProgram);

    glGetProgramiv(this->m_shaderProgram, GL_LINK_STATUS, &statusSuccess);
    if (!statusSuccess) {
        glGetProgramInfoLog(this->m_shaderProgram, infologLength, NULL, infolog);
        Debug::LogError("Failed to link shaders, shader program will be unusable:\n\t" + String(infolog));
    } 

    glDeleteShader(vert);
    glDeleteShader(frag);

}


void Shader::Use() {
    glUseProgram(this->m_shaderProgram);
}


int Shader::GetUniformLocation(const String &uniform) {
    for (auto element : this->m_locationCache) {
        if (element.first == uniform) {
            return element.second;
        }
    }

    
    int location = glGetUniformLocation(this->m_shaderProgram, uniform.c_str());
    this->m_locationCache[uniform] = location;
    return location;
}



void Shader::SetUniform(const String &uniform, const float &value) {
    const int location = this->GetUniformLocation(uniform);
    glUniform1f(location, value);
}
void Shader::SetUniform(const String &uniform, const Vec2 &value) {
    const int location = this->GetUniformLocation(uniform);
    glUniform2f(location, value.x, value.y);
}
void Shader::SetUniform(const String &uniform, const Vec3 &value) {
    const int location = this->GetUniformLocation(uniform);
    glUniform3f(location, value.x, value.y, value.z);
}
void Shader::SetUniform(const String &uniform, const Vec4 &value) {
    const int location = this->GetUniformLocation(uniform);
    glUniform4f(location, value.x, value.y, value.z, value.w);
}



String Shader::GetShaderSource(ShaderType type) {
    switch (type) {
        case ShaderType::FRAG:
            return this->m_pathFrag;
        case ShaderType::VERTEX:
            return this->m_pathVert;
    }
    return "[NO SOURCE]";
}

Shader::~Shader() {
    glDeleteProgram(this->m_shaderProgram);
}

