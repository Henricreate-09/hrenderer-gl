#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

void _FramebufferSizeCallback(GLFWwindow *window, int w, int h) {
    glViewport(0, 0, w, h);
}


int main(void) {
    if (!glfwInit()) {
        std::cerr << "Failed to init GLFW!\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow *window = glfwCreateWindow(800, 600, "GLFW Window", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Error creating window!\n";
        glfwTerminate();

        const char* desc;
        glfwGetError(&desc);
        std::cerr << desc;

        return -1;
    }
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Error loading GLAD!\n";
        glfwTerminate();
        return -1;
    }


    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, _FramebufferSizeCallback);

    while (!glfwWindowShouldClose(window))  {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(window, true);
        
        glClearColor(0.4f, 0.2f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}