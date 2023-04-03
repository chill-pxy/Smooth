#include "runtime/tool/render/render_pipeline_base.h"
#include "runtime/tool/ui/window_ui.h"

namespace Smooth
{
    void RenderPipelineBase::initialize(){}

    void RenderPipelineBase::forwardRender(){}

    void RenderPipelineBase::deferredRender(){}

    void RenderPipelineBase::initializeRenderBackend(WindowUI* window_ui)
    {
        m_ui_pass->initializeUIRenderBackend(window_ui);
    }
}