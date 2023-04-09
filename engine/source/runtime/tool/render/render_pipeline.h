#pragma once

#include "runtime/tool/render/render_pipeline_base.h"

#include "runtime/tool/render/legacy/skybox.h"
#include "runtime/tool/render/legacy/shader.h"
#include "runtime/tool/render/default_camera.h"

namespace Smooth
{
    class RenderPipeline : public RenderPipelineBase
    {
    public:
        virtual void initialize() override final;
        virtual void forwardRender() override final;
        virtual void deferredRender() override final;
    
    private:
        Shader m_skybox_shader;
        Skybox m_skybox;
        DefaultCamera* m_default_camera;
    };
}