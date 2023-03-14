#include "GLFW/glfw3.h"

namespace Smooth
{
    class WindowSystem
    {
    public:
        WindowSystem() = default;
        ~WindowSystem();

        void        initialize();
        bool        ShouldClose();
        GLFWwindow* getWindow() const;

    private:
        GLFWwindow* m_window {nullptr};

    };
}