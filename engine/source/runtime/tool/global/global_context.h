#pragma once

#include <memory>

namespace Smooth
{
    class WindowSystem;

    class RuntimeGlobalContext
    {
    public:
        void startSystems();
        void shudownSystems();
    
    public:
        std::shared_ptr<WindowSystem> m_window_system;

    };

    extern RuntimeGlobalContext g_runtime_global_context;
}