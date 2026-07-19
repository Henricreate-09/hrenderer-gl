#pragma once

#include <glad/glad.h>
#include <map>

#include "../Core/Core.hpp"


enum ShaderType {
    VERTEX,
    FRAG
};

class Shader {
private:
    unsigned int m_shaderProgram;

    std::map<String, int> m_locationCache;

    String m_pathVert;
    String m_pathFrag;

public:
    Shader(const String &name);
    ~Shader();

    void Use();

    int GetUniformLocation(const String &uniform);

    void SetUniform(const String &uniform, const float &value);
    void SetUniform(const String &uniform, const Vec2 &value);
    void SetUniform(const String &uniform, const Vec3 &value);
    void SetUniform(const String &uniform, const Vec4 &value);

    String GetShaderSource(ShaderType type);
};