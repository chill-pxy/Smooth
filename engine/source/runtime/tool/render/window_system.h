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
        bool        ShouldClose() const;
        GLFWwindow* getWindow() const;

    private:
        GLFWwindow* m_window {nullptr};
    };
}