#include "VAO.hpp"

VAO::VAO() {
    glGenVertexArrays(1, &this->m_ID);
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &this->m_ID);
}

void VAO::SetData(unsigned int pointerIndex) {
    this->m_pointerIndex = pointerIndex;
    glVertexAttribPointer(this->m_pointerIndex, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
    glEnableVertexAttribArray(this->m_pointerIndex);
}

void VAO::Bind()
{
    glBindVertexArray(this->m_ID);
}
