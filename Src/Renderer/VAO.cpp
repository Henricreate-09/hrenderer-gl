#include "VAO.hpp"

VAO::VAO() {
    glGenVertexArrays(1, &this->m_ID);
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &this->m_ID);
}

void VAO::SetDataVec3(const GLuint &pointerIndex, const GLuint &elementAmount, const GLuint &offsetAmount) {
    glVertexAttribPointer(
        pointerIndex,
        3,
        GL_FLOAT,
        GL_FALSE, 
        sizeof(float) * elementAmount,
        (void*)(sizeof(float) * offsetAmount)
    );
    glEnableVertexAttribArray(pointerIndex);
}

void VAO::Bind()
{
    glBindVertexArray(this->m_ID);
}
