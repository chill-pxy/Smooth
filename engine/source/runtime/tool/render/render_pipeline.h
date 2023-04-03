#pragma once

#include "runtime/tool/render/render_pipeline_base.h"

namespace Smooth
{
    class RenderPipeline : public RenderPipelineBase
    {
        virtual void initialize() override final;
        virtual void forwardRender() override final;
        virtual void deferredRender() override final;
    };
}