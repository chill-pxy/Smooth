#pragma once

#include "GLFW/glfw3.h"

namespace Smooth
{
    struct WindowInfo
    {
        int         width {1280};
        int         height {720};
        const char* title {"Smooth"};
    };

    class WindowSystem
    {
    public:
        WindowSystem() = default;
        ~WindowSystem();

        void        initialize(WindowInfo window_info);

        bool        shouldClose() const { return glfwWindowShouldClose(m_window); }
        GLFWwindow* getWindow() const { return m_window; }
        void        pollEvents() const { glfwPollEvents(); }

    private:
        GLFWwindow* m_window {nullptr};
    };
}