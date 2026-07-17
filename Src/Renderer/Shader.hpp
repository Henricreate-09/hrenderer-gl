#pragma once

#include <glad/glad.h>
#include "../Core/Core.hpp"

enum ShaderType {
    VERTEX,
    FRAG
};

class Shader {
private:
    unsigned int m_shaderProgram;
    
    String m_pathVert;
    String m_pathFrag;

public:
    Shader(const String &vertSource, const String &fragSource);
    ~Shader();

    void Use();

    String GetShaderSource(ShaderType type);
};