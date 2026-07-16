#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


class RenderWindow {
    private:
    GLFWwindow *m_window;

    int m_width;
    int m_height;
    std::string m_title;
    bool m_isRunning;

    bool m_isResizeable;
    bool m_isFullscreen;

    public:
    RenderWindow(const int &w, const int &h, const std::string &title);
    ~RenderWindow();

    void WindowLoop();
    void Quit();
    bool IsRunning();
    

    // Window property setters
    void SetTitle(const std::string &newTitle);
    void SetSize(const int &width, const int &height);
    void SetResizeable(const bool &option);
    void SetFullscreen(const bool &option);
};