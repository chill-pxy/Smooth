#pragma once

#include <chrono>

namespace Smooth
{
    class SmoothEngine
    {
        friend class SmoothEditor;

        static const float s_fps_alpha;

    public:
        void startEngine(const std::string& config_file_path);
        void shutdownEngine();

        void run();
        bool tickOneFrame(float delta_time);
        bool isQuit() const {return m_is_quit;}
        int  getFPS() const {return m_fps;}

    protected:
        float calculateDeltaTime();
        void  calculateFPS(float delta_time);
        void  logicalTick(float delta_time);
        bool  rendererTick(float delta_time);

    protected:
        bool  m_is_quit {false};
        float m_average_duration {0.f};
        int   m_frame_count {0};
        int   m_fps {0};

        std::chrono::steady_clock::time_point m_last_tick_time_point {std::chrono::steady_clock::now()};
    };
}