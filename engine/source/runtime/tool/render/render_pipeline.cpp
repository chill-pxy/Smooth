#include <iostream>

#include "render_pipeline.h"
#include "runtime/tool/render/passes/ui_pass.h"

namespace Smooth
{
    void RenderPipeline::initialize()
    {
        m_ui_pass = std::make_shared<UIPass>();
    }

    void RenderPipeline::forwardRender()
    {
        
    }

    void RenderPipeline::deferredRender()
    {
        //UIPass& ui_pass = *(static_cast<UIPass*>(m_ui_pass.get()));
        std::cout<<"deferredRender is run"<<std::endl;
        static_cast<UIPass*>(m_ui_pass.get())->draw();
    }
}