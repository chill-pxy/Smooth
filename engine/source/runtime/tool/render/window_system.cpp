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

        glfwSetWindowUserPointer(m_window,this);
        glfwSetKeyCallback(m_window,keyCallback);
        glfwSetWindowSizeCallback(m_window,windowSizeCallback);
        glfwSetWindowCloseCallback(m_window,windowCloseCallback);
    }

    //-------------------------------------------------------------------------------
    
    void WindowSystem::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if(app){ app->onKey(key,scancode,action,mods); }
    }

    void WindowSystem::windowSizeCallback(GLFWwindow* window, int width, int height)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if(app)
        { 
            app->m_width  = width;
            app->m_height = height;    
        }
    }
    
    void WindowSystem::windowCloseCallback(GLFWwindow* window)
    {
        glfwSetWindowShouldClose(window,true);
    }

    void  WindowSystem::onKey(int key, int scancode, int action, int mods)
    {
        for(auto& func : m_onKeyFunc)
            func(key,scancode,action,mods);
    }
    
}