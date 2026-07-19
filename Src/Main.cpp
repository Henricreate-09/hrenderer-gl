#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core/Core.hpp"
#include "Renderer/Renderer.hpp"

using namespace std;

void _FramebufferSizeCallback(GLFWwindow *window, int w, int h) {
    glViewport(0, 0, w, h);
}

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "\n"
    "void main() {\n"
    "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0    ";


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


    float vertices[] = {
        -0.5f, 0.5f, 0.f,
        0.5f, 0.5f, 0.f,
        -0.5f, -0.5f, 0.f,
        0.5f, -0.5f, 0.f
    };
    unsigned int indices[] = {
        0, 1, 2,
        1, 2, 3
    };

    VBO modelVBO;
    EBO modelEBO;
    VAO modelVAO;

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    modelVAO.Bind();

    modelVBO.Bind();
    modelVBO.SetData(vertices, sizeof(vertices));
    
    modelEBO.Bind();
    modelEBO.SetData(indices, sizeof(indices));
    

    modelVAO.SetData(0);
    
    Shader defShader("Shaders/HiShaderVert.glsl", "Shaders/HiShaderFrag.glsl");
    
    while (!glfwWindowShouldClose(window))  {
        glfwPollEvents();
        if (glfwGetKey(window, GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(window, true);
        
        
        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        modelVAO.Bind();
        modelEBO.Bind();
        defShader.Use();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        
        glfwSwapBuffers(window);
    }
    

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}