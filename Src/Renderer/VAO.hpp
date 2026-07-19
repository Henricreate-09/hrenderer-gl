#pragma once

#include <glad/glad.h>

class VAO {
private: 
    unsigned int m_ID;

public:
    VAO();
    ~VAO();

    void SetDataVec3(const GLuint &pointerIndex, const GLuint &elementAmount, const GLuint &offset);
    void Bind();
};