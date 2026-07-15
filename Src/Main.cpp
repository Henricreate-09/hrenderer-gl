#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;


int main(void) {
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(800, 600, "porra", NULL, NULL);

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))  {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}