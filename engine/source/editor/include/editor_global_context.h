#pragma once 

namespace Smooth
{
    struct EditorGlobalContextInitInfo
    {
        class WindowSystem* window_system;
        class RenderSystem* render_system;
        class SmoothEngine* engine_runtime;
    };

    class EditorGlobalContext
    {
    public:
        class WindowSystem*       m_window_system {nullptr};
        class RenderSystem*       m_render_system {nullptr};
        class SmoothEngine*       m_engine_runtime {nullptr};
        class EditorInputManager* m_input_manager {nullptr};
        class EditorSceneManager* m_scene_manager {nullptr};
        class EditorLanguage*     m_editor_language {nullptr};
        
    public:
        void initialize(const EditorGlobalContextInitInfo& init_info);
        void clear();
    };

    extern EditorGlobalContext g_editor_global_context;
}