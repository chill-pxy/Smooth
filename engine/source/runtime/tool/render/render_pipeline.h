#pragma once

#include "runtime/tool/render/render_pipeline_base.h"

#include "runtime/tool/render/legacy/skybox.h"
#include "runtime/tool/render/legacy/shader.h"

#include "editor/include/editor_scene_manager.h"
#include "editor/include/editor_global_context.h"

namespace Smooth
{
    class RenderPipeline : public RenderPipelineBase
    {
    public:
        virtual void initialize() override final;
        virtual void forwardRender() override final;
        virtual void deferredRender() override final;
    
    private:
        std::shared_ptr<Shader> m_skybox_shader;
        std::shared_ptr<Skybox> m_skybox;
    };
}