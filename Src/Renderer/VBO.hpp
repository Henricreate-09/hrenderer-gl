#pragma once

#include <glad/glad.h>

class VBO {
private: 
    unsigned int m_ID;

public:
    VBO();
    ~VBO();

    void SetData(const void *verticesArray, const int &size);
    void Bind();
};