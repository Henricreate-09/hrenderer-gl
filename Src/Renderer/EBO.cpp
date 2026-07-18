#include "EBO.hpp"

EBO::EBO() {
    glGenBuffers(1, &this->m_ID);
}

EBO::~EBO() {
    glDeleteBuffers(1, &this->m_ID);
}

// TODO: Make this function use templates so you don't need to pass the size
void EBO::SetData(const void *indicesArray, const int &size) {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicesArray, GL_STATIC_DRAW);
}

void EBO::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ID);
}
