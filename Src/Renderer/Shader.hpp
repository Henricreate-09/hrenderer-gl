#pragma once

#include <glad/glad.h>
#include "../Core/Core.hpp"
#include <iostream>
#include <cstdio>
#include <string.h>

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

    int GetUniformLocation(const String &uniform);

    void SetUniform(const String &uniform, const float &value);
    void SetUniform(const String &uniform, const Vec2 &value);
    void SetUniform(const String &uniform, const Vec3 &value);
    void SetUniform(const String &uniform, const Vec4 &value);

    String GetShaderSource(ShaderType type);
};