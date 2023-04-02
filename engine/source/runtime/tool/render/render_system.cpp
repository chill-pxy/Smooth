#include "runtime/tool/render/render_system.h"

namespace Smooth
{
    RenderSystem::~RenderSystem()
    {
        clear();
    }

    void RenderSystem::initialize(RenderSystemInitInfo init_info)
    {

    }

    void RenderSystem::tick(float delta_time)
    {
        m_render_pipeline->deferredRender();
    }

    void RenderSystem::clear()
    {
        m_render_pipeline.reset();
    }
}