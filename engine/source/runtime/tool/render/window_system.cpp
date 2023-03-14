#include <iostream>

#include "window_system.h"

namespace Smooth
{
    WindowSystem::~WindowSystem()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void WindowSystem::initialize()
    {
        if(!glfwInit())
        {
            std::cout<<"无法初始化GLFW";
            return;
        }
    }
}