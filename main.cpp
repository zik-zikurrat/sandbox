#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>



int main(int, char**){
    if (!glfwInit()){
        std::cerr << "Cannot run GLFW" << std::endl;
        return -1;
    }


    GLFWmonitor* primary = glfwGetPrimaryMonitor();

    int count;

    GLFWmonitor** monitors = glfwGetMonitors(&count);

    std::cout << "Monitors count: " << count << "\n";


    const GLFWvidmode* mode = glfwGetVideoMode(primary);

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "HYI", primary, NULL);
    if(!window){
        std::cerr << "Cannot create window!"<< std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Cannot run GLAD!" << std::endl;
        return -1;
    }

    std::cout << "All systems are running! OpenGL version is: " << glGetString(GL_VERSION) << "\n";

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.15f, 0.15f, 0.18f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
