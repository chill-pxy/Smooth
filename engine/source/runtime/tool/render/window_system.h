#pragma once

#include <functional>

#include "glad/glad.h"
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

        void              initialize(WindowInfo window_info);
        bool              shouldClose() const { return glfwWindowShouldClose(m_window); }
        GLFWwindow*       getWindow() const { return m_window; }
        std::array<int,2> getWindowSize() const { return std::array<int,2>({m_width, m_height}); }
        int               getWindowWidth() const { return m_width; }
        int               getWindwoHeight() const { return m_height; }
        void              pollEvents() const { glfwPollEvents(); }
        void              swapBuffers() const { glfwSwapBuffers(m_window); }

        typedef std::function<void(int,int,int,int)> onKeyFunc;

        void registerOnKeyFunc(onKeyFunc func) { m_onKeyFunc.push_back(func); }

    protected:
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void windowSizeCallback(GLFWwindow* window, int width, int height);
        static void windowCloseCallback(GLFWwindow* window);

        void onKey(int key, int scancode, int action, int mods);  

    private:
        GLFWwindow* m_window {nullptr};
        int         m_width {0};
        int         m_height {0};

        std::vector<onKeyFunc> m_onKeyFunc;
    };
}