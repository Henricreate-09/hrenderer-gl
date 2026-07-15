#pragma once

#include <GLFW/glfw3.h>
#include <iostream>


class RenderWindow {
    private:
    GLFWwindow *m_window;

    size_t m_width;
    size_t m_height;
    std::string m_title;

    public:
    RenderWindow(size_t w, size_t h, std::string title) : 
        m_width(w), m_height(h), m_title(title) {
            // do things
    }
    ~RenderWindow() {
        glfwDestroyWindow(this->m_window);
    }

    void UpdateWindow() {

    }
};