#include "RenderWindow.hpp"

void _GLFramebufferResize(GLFWwindow *window, int w, int h) {
    glViewport(0, 0, w, h);
    // TODO: This function must set the new width and height of the window
}




RenderWindow::RenderWindow(const int &w, const int &h, const std::string &title) {
    if (!glfwInit()) {
        std::cerr << "Failed to init GLFW!\n";
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // TODO: Make window flag functions work later
    //glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    this->m_width = w;
    this->m_height = h;
    this->m_title = title;

    this->m_window = glfwCreateWindow(
        this->m_width,
        this->m_height,
        this->m_title.c_str(),
        nullptr, nullptr
    );
    if (this->m_window == nullptr) {
        std::cerr << "Error creating window!\n";
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    this->m_isRunning = true;
    glfwMakeContextCurrent(this->m_window);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Error loading GLAD!\n";
        glfwTerminate();
        exit(EXIT_FAILURE);
    }


    glViewport(0, 0, this->m_width, this->m_height);
    glfwSetFramebufferSizeCallback(this->m_window, _GLFramebufferResize);
}


RenderWindow::~RenderWindow() {
    glfwDestroyWindow(this->m_window);
    glfwTerminate();
}

void RenderWindow::WindowLoop() {
    glfwPollEvents();

    // TODO: Make a function to set the window color(uses the Color.hpp class)
    glClearColor(0.251f, 0.122f, 0.812f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    if (glfwGetKey(this->m_window, GLFW_KEY_ESCAPE) ||
        glfwWindowShouldClose(this->m_window)
    ) {
        this->Quit();
    }

    glfwSwapBuffers(this->m_window);
}

void RenderWindow::Quit() {
    this->m_isRunning = false;
    glfwSetWindowShouldClose(this->m_window, true);
}

bool RenderWindow::IsRunning() {
    return this->m_isRunning;
}

void RenderWindow::SetTitle(const std::string &newTitle) {
    glfwSetWindowTitle(this->m_window, newTitle.c_str());
}