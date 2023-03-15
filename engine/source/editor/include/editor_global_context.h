#pragma once 

namespace Smooth
{
    struct EditorGlobalContextInitInfo
    {
        class WindowSystem* window_system;
        class SmoothEngine* engine_runtime;
    };

    class EditorGlobalContext
    {
    public:
        class WindowSystem* m_window_system {nullptr};
        class SmoothEngine* m_engine_runtime {nullptr};

    public:
        void initialize(const EditorGlobalContextInitInfo& init_info);
        void clear();
    };

    extern EditorGlobalContext g_editor_global_context;
}