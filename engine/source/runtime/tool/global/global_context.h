#pragma once

#include <assert.h>
#include <memory>

namespace Smooth
{
    class WindowSystem;
    class InputSystem;
    class RenderSystem;

    class RuntimeGlobalContext
    {
    public:
        void startSystems();
        void shudownSystems();
    
    public:
        std::shared_ptr<WindowSystem> m_window_system;
        std::shared_ptr<InputSystem>  m_input_system;
        std::shared_ptr<RenderSystem> m_render_system;
    };

    extern RuntimeGlobalContext g_runtime_global_context;
}