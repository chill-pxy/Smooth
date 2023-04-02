#pragma once

#include "runtime/tool/render/render_pass_base.h"

namespace Smooth
{
    class RenderPass : public RenderPassBase
    {
    public:
        void initialize() override;

        virtual void draw();
    };
}