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
            std::cout<<"failed to init GLFW"<<std::endl;
            return;
        }

        m_width  = window_info.width;
        m_height = window_info.height;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        m_window = glfwCreateWindow(window_info.width,
                                  window_info.height,
                                  window_info.title,
                                  nullptr,
                                  nullptr);
        if(!m_window)
        {
            std::cout<<"failed to creat window"<<std::endl;
            return;
        }

        glfwMakeContextCurrent(m_window);
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        {
            std::cout << "failed to load opengl";
        }

        glViewport(0,0,m_width,m_height);
        glfwSetWindowUserPointer(m_window,this);
        glfwSetKeyCallback(m_window,keyCallback);
        glfwSetWindowSizeCallback(m_window,windowSizeCallback);
        glfwSetWindowCloseCallback(m_window,windowCloseCallback);

        glfwSwapInterval(1);     
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

    void WindowSystem::onKey(int key, int scancode, int action, int mods)
    {
        for(auto& func : m_onKeyFunc)
            func(key,scancode,action,mods);
    }
    
    void WindowSystem::setFocusMode(bool mode)
    {
        m_is_focus_mode = mode;
        glfwSetInputMode(m_window, GLFW_CURSOR, m_is_focus_mode ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
    }
}