#include <iostream>
#include <assert.h>

#include "runtime/tool/render/render_system.h"
#include "runtime/tool/render/render_pipeline.h"

namespace Smooth
{
    RenderSystem::~RenderSystem()
    {
        clear();
    }

    void RenderSystem::initialize(RenderSystemInitInfo init_info)
    {
        m_render_pipeline = std::make_shared<RenderPipeline>();

        m_render_pipeline->initialize();
    }

    void RenderSystem::tick(float delta_time)
    {
        std::cout<<"render system tick"<<std::endl;
        assert(m_render_pipeline);
        m_render_pipeline->deferredRender();
    }

    void RenderSystem::clear()
    {
        m_render_pipeline.reset();
    }

    void RenderSystem::initializeUIRenderBackend(WindowUI* window_ui)
    {
        m_render_pipeline->initializeRenderBackend(window_ui);
    }
}