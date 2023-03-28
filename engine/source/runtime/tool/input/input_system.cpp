#include "runtime/tool/global/global_context.h"
#include "runtime/tool/input/input_system.h"
#include "runtime/tool/render/window_system.h"

namespace Smooth
{
    void InputSystem::initialize()
    {
        std::shared_ptr<WindowSystem> window_system = g_runtime_global_context.m_window_system;
        assert(window_system);

        window_system->registerOnKeyFunc(std::bind(&InputSystem::onKey,
                                                    this,
                                                    std::placeholders::_1,
                                                    std::placeholders::_2,
                                                    std::placeholders::_3,
                                                    std::placeholders::_4));

    }

    void InputSystem::tick()
    {
        std::shared_ptr<WindowSystem> window_system = g_runtime_global_context.m_window_system;
        
    }

    void InputSystem::onKey(int key,int scancode,int action,int mods)
    {

    }
}