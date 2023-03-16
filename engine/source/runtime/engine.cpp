#include <iostream>

#include "runtime/engine.h"
#include "runtime/tool/global/global_context.h"

#include "runtime/tool/render/window_system.h"


namespace Smooth
{
    void SmoothEngine::startEngine()
    {
        g_runtime_global_context.startSystems();
        std::cout<<"��������"<<std::endl;
    }

    void SmoothEngine::shutdownEngine()
    {
        g_runtime_global_context.shudownSystems();
        std::cout<<"����ر�"<<std::endl;
    }

    //--------------------------------------------------------------------------

    void SmoothEngine::run()
    {
        std::shared_ptr<WindowSystem> window_system = g_runtime_global_context.m_window_system;
        
        while (!window_system->shouldClose())
        {
            const float delta_time = calculateDeltaTime();
            tickOneFrame(delta_time);
        }
    }

    bool SmoothEngine::tickOneFrame(float delta_time)
    {
        logicalTick(delta_time);
        calculateFPS(delta_time);

        g_runtime_global_context.m_window_system->pollEvents();

        const bool should_window_close = g_runtime_global_context.m_window_system->shouldClose();
        return !should_window_close;
    }

    //---------------------------------------------------------------------------

    float SmoothEngine::calculateDeltaTime()
    {
        using namespace std::chrono;

        float delta_time;
        steady_clock::time_point tick_time_point = steady_clock::now();

        duration<float> time_span = duration_cast<duration<float>>(tick_time_point - m_last_tick_time_point);
        delta_time                = time_span.count();

        m_last_tick_time_point = tick_time_point;

        return delta_time;
    }

    void SmoothEngine::calculateFPS(float delta_time)
    {

    }

    void SmoothEngine::logicalTick(float delta_time)
    {
        
    }

    bool SmoothEngine::rendererTick()
    {
        return true;
    }


}