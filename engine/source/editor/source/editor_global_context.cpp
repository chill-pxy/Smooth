#include "editor_global_context.h"
#include "editor_input_manager.h"
#include "editor_scene_manager.h"

namespace Smooth
{
    EditorGlobalContext g_editor_global_context;
    
    void EditorGlobalContext::initialize(const EditorGlobalContextInitInfo& init_info)
    {
        g_editor_global_context.m_window_system  = init_info.window_system;
        g_editor_global_context.m_render_system  = init_info.render_system;
        g_editor_global_context.m_engine_runtime = init_info.engine_runtime;
        
        m_input_manager = new EditorInputManager();
        m_scene_manager = new EditorSceneManager();

        m_input_manager->initialize();
        m_scene_manager->initialize();
    }

    void EditorGlobalContext::clear()
    {
        delete(m_input_manager);
        return;
    }
}