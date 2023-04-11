#include "runtime/tool/global/global_context.h"
#include "runtime/tool/input/input_system.h"
#include "runtime/tool/render/window_system.h"
#include "runtime/tool/render/default_camera.h"

#include "engine.h"

namespace Smooth
{
    unsigned int k_complement_control_command = 0xFFFFFFFF;

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
        window_system->registerOnCursorPosFunc(std::bind(&InputSystem::onCursorPos,
                                                    this,
                                                    std::placeholders::_1,
                                                    std::placeholders::_2));
    }

    void InputSystem::tick()
    {
        std::shared_ptr<WindowSystem> window_system = g_runtime_global_context.m_window_system;
        if(window_system->getFocusMode())
        {
             
        }
    }

    void InputSystem::clear()
    {
        m_cursor_delta_x = 0;
        m_cursor_delta_y = 0;
    }

    void InputSystem::calculateCursorDeltaAngles()
    {
        std::array<int, 2> window_size = g_runtime_global_context.m_window_system->getWindowSize();

        if(window_size[0] <1 || window_size[1] <1){return;}
    }

    void InputSystem::onKey(int key,int scancode,int action,int mods)
    {
        if(!g_is_editor_mode)
        {
            onKeyInDisplayMode(key, scancode, action, mods);
        }
    }

    void InputSystem::onCursorPos(double current_cursor_x, double current_cursor_y)
    {
        if(g_runtime_global_context.m_window_system->getFocusMode())
        {
            m_cursor_delta_x = m_last_cursor_x - current_cursor_x;
            m_cursor_delta_y = m_last_cursor_y - current_cursor_y;
        }
        m_last_cursor_x = current_cursor_x;
        m_last_cursor_y = current_cursor_y;
    }

    void InputSystem::onKeyInDisplayMode(int key, int scancode, int action, int mods)
    {

    }
}