#include "VBO.hpp"

VBO::VBO() {
    glGenBuffers(1, &this->m_ID);
}

VBO::~VBO() {
    glDeleteBuffers(1, &this->m_ID);
}

// TODO: Make this function use templates so you don't need to pass the size
void VBO::SetData(const void *verticesArray, const int &size) {
    glBufferData(GL_ARRAY_BUFFER, size, verticesArray, GL_STATIC_DRAW);
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, this->m_ID);
}
