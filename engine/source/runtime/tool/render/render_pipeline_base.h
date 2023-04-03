#pragma once

#include <memory>

#include "runtime/tool/render/render_pass_base.h"

namespace Smooth
{
    class WindowUI;

    class RenderPipelineBase
    {
        friend class RenderSystem;
    
    public:
        virtual ~RenderPipelineBase() {};
        
        virtual void clear() {};
        virtual void initialize();

        //virtual void preparePassData();
        virtual void forwardRender();
        virtual void deferredRender();

        void initializeRenderBackend(WindowUI* window_ui);
    
    protected:
        std::shared_ptr<RenderPassBase> m_ui_pass;
    };
}