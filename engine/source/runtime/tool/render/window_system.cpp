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
            std::cout<<""
        }
    }
}