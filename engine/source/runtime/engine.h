#pragma once

#include <chrono>

namespace Smooth
{
    class SmoothEngine
    {
        friend class SmoothEditor;

    public:
        void startEngine();
        void shutdownEngine();
        void run();

    protected:
        float calculateDeltaTime();
        std::chrono::steady_clock::time_point m_last_tick_time_point {std::chrono::steady_clock::now()};
    };
}