#include "render_pipeline.h"
#include "runtime/tool/render/passes/ui_pass.h"

namespace Smooth
{
    void RenderPipeline::initialize()
    {
        
    }

    void RenderPipeline::forwardRender()
    {
        
    }

    void RenderPipeline::deferredRender()
    {
        //UIPass& ui_pass = *(static_cast<UIPass*>(m_ui_pass.get()));
        static_cast<UIPass*>(m_ui_pass.get())->draw();
    }
}