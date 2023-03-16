#include <iostream>

#include "window_system.h"

namespace Smooth
{
    WindowSystem::~WindowSystem()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void WindowSystem::initialize(WindowInfo window_info)
    {
        if(!glfwInit())
        {
            std::cout<<"无法初始化GLFW"<<std::endl;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        
        m_window=glfwCreateWindow(window_info.width,
                                  window_info.height,
                                  window_info.title,
                                  nullptr,
                                  nullptr);
        if(!m_window)
        {
            std::cout<<"无法创建窗口"<<std::endl;
            return;
        }
    }
    
}