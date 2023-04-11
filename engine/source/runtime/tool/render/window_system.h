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
        typedef std::function<void(double, double)>  onCursorPosFunc;
        typedef std::function<void(int)>             onCursorEnterFunc;
        typedef std::function<void()>                onWindowCloseFunc;
        typedef std::function<void(int,int,int)>     onMouseButtonFunc;

        void registerOnKeyFunc(onKeyFunc func) { m_onKeyFunc.push_back(func); }
        void registerOnCursorPosFunc(onCursorPosFunc func) { m_onCursorPosFunc.push_back(func); }
        void registerOnCursorEnter(onCursorEnterFunc func) { m_onCursorEnterFunc.push_back(func); }
        void registerOnWindowClose(onWindowCloseFunc func) { m_onWindowCloseFunc.push_back(func); }
        void registerOnMouseButton(onMouseButtonFunc func) { m_onMouseButtonFunc.push_back(func);}

        bool isMouseButtonDown(int button) const
        {
            if(button < GLFW_MOUSE_BUTTON_1 || button > GLFW_MOUSE_BUTTON_LAST)
            {
                return false;
            }
            return glfwGetMouseButton(m_window, button) == GLFW_PRESS;
        }

        bool getFocusMode() const { return m_is_focus_mode; }
        void setFocusMode(bool mode);

    protected:
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void windowSizeCallback(GLFWwindow* window, int width, int height);
        static void windowCloseCallback(GLFWwindow* window);
        static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
        static void cursorEnterCallback(GLFWwindow* window, int entered);

        void onKey(int key, int scancode, int action, int mods);
        void onMouseButton(int button, int action, int mods);
        void onCursorPos(double xpos, double ypos);
        void onCursorEnter(int entered);

    private:
        GLFWwindow* m_window {nullptr};
        int         m_width {0};
        int         m_height {0};  

        bool m_is_focus_mode{false};

        std::vector<onKeyFunc>         m_onKeyFunc;
        std::vector<onCursorPosFunc>   m_onCursorPosFunc;
        std::vector<onCursorEnterFunc> m_onCursorEnterFunc;
        std::vector<onWindowCloseFunc> m_onWindowCloseFunc;
        std::vector<onMouseButtonFunc> m_onMouseButtonFunc;
    };
}