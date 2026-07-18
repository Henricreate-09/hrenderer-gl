#pragma once

#include <glad/glad.h>

class EBO {
private: 
    unsigned int m_ID;

public:
    EBO();
    ~EBO();

    void SetData(const void *indicesArray, const int &size);
    void Bind();
};