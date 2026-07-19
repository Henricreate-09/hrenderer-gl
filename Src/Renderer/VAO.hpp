#pragma once

#include <glad/glad.h>

class VAO {
private: 
    unsigned int m_ID;
    unsigned int m_pointerIndex;

public:
    VAO();
    ~VAO();

    void SetData(unsigned int pointerIndex);
    void Bind();
};