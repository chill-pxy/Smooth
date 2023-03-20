#include <iostream>

#include "editor.h"
#include "editor_global_context.h"

#include "runtime/engine.h"
#include "runtime/tool/global/global_context.h"

namespace Smooth
{
    void SmoothEditor::initialize(SmoothEngine* engine_runtime)
    {
        assert(engine_runtime);
        m_engine_runtime=engine_runtime;

        EditorGlobalContextInitInfo init_info = {g_runtime_global_context.m_window_system.get(),
                                                 engine_runtime};
                                                
        g_editor_global_context.initialize(init_info);
        
        std::cout<<"±à¼­Æ÷³õÊ¼»¯"<<std::endl;
    }

    void SmoothEditor::clear()
    {
        std::cout<<"±à¼­Æ÷¹Ø±Õ"<<std::endl;
    }

    void SmoothEditor::run()
    {
        std::cout<<"±à¼­Æ÷Æô¶¯"<<std::endl;

        assert(m_engine_runtime);
        
        float delta_time;
        while(true)
        {
            delta_time=m_engine_runtime->calculateDeltaTime();
            if(!m_engine_runtime->tickOneFrame(delta_time)) return;
        } 
    }
}