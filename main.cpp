#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


GLFWwindow *drawWindow(GLFWmonitor* monitor){
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "HYI", monitor, NULL);
    if(!window){
        std::cerr << "Cannot create window!"<< std::endl;
        return NULL;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Cannot run GLAD!" << std::endl;
        return NULL;
    }

    return window;
}


void showWindow(GLFWwindow *window){
    while(!glfwWindowShouldClose(window)){
        glClearColor(0.15f, 0.15f, 0.18f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}


void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods, GLFWmonitor **monitors){
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        glfwDestroyWindow(window);
        GLFWwindow *window = drawWindow(monitors[1]);
        showWindow(window);
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
        glfwDestroyWindow(window);
        GLFWwindow *window = drawWindow(monitors[0]);
        showWindow(window);
    }
}

struct Window {
    public:
        int init(){
            if(!glfwInit()){
                return -1;
            }
            // glfwSetErrorCallback()
            return 0;
        }

        int build(GLFWmonitor *primaryMonitor){
            const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

            glfwWindowHint(GLFW_RED_BITS, mode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

            m_window = glfwCreateWindow(mode->width, mode->height, "HYI", primaryMonitor, NULL);
            if(!m_window){
                std::cerr << "Cannot create window!"<< std::endl;
                return NULL;
            }

            glfwMakeContextCurrent(m_window);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
                std::cerr << "Cannot run GLAD!" << std::endl;
                return NULL;
            }

            return m_window;
        }

    private:
        GLFWwindow *m_window;
};





int main(int, char**){
    if (!glfwInit()){
        std::cerr << "Cannot run GLFW" << std::endl;
        return -1;
    }


    int monitorsCount;
    GLFWmonitor** monitors = glfwGetMonitors(&monitorsCount);

    GLFWmonitor* firstMonitor = monitors[0];
    GLFWmonitor* secondMonitor = monitors[1];

    std::cout << "Monitors count: " << monitorsCount << "\n";

    int shouldEnd = false;

    GLFWwindow *window = drawWindow(firstMonitor);

    while(!shouldEnd){

       glfwPollEvents();
    }

    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    glfwTerminate();

    return 0;
}


// создать структуру 