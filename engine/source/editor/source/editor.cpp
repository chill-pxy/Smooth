#include <iostream>

#include "editor.h"
#include "editor_ui.h"
#include "editor_global_context.h"
#include "editor_input_manager.h"
#include "editor_scene_manager.h"

#include "runtime/engine.h"
#include "runtime/tool/global/global_context.h"
#include "runtime/tool/render/render_system.h"

namespace Smooth
{
    void SmoothEditor::initialize(SmoothEngine* engine_runtime)
    {
        assert(engine_runtime);
        g_is_editor_mode = true;
        m_engine_runtime = engine_runtime;

        EditorGlobalContextInitInfo init_info = {g_runtime_global_context.m_window_system.get(),
                                                 g_runtime_global_context.m_render_system.get(),
                                                 engine_runtime};
                                                
        g_editor_global_context.initialize(init_info);
        // g_editor_global_context.m_scene_manager->setEditorCamera(
        //     g_runtime_global_context.m_render_system->g
        // )

        m_editor_ui = std::make_shared<EditorUI>();
        WindowUIInitInfo ui_init_info = {g_runtime_global_context.m_window_system,
                                        g_runtime_global_context.m_render_system};
        m_editor_ui->initialize(ui_init_info);
        
        std::cout<<"editor initialize"<<std::endl;
    }

    void SmoothEditor::clear()
    {
        g_editor_global_context.clear();
        std::cout<<"editor clear"<<std::endl;
    }

    void SmoothEditor::run()
    {
        assert(m_engine_runtime);
        assert(m_editor_ui);

        std::cout<<"editor run"<<std::endl;

        float delta_time;
        while(true)
        {
            delta_time=m_engine_runtime->calculateDeltaTime();
            g_editor_global_context.m_scene_manager->tick(delta_time);
            g_editor_global_context.m_input_manager->tick(delta_time);
            if(!m_engine_runtime->tickOneFrame(delta_time)) return;
        } 
    }
}