#include "Debug.hpp"

void Debug::Log(String info) {
    std::cout << info << '\n';
}

void Debug::LogWarning(String info) {
    std::cout << "WARNING: " << info << '\n';
}

void Debug::LogError(String info) {
    std::cout << "ERROR: " << info << '\n';
}

void Debug::ErrorCrash(String error) {
    Debug::LogError(error);
    exit(EXIT_FAILURE);
}

String Debug::GetGLFWError() {
    const char *desc;
    glfwGetError(&desc);
    return desc;
}
