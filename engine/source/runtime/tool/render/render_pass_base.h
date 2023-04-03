#pragma once

namespace Smooth
{
    class WindowUI;

    class RenderPassBase
    {
    public:
        virtual void initialize();
        virtual void preparePassData();
        virtual void initializeUIRenderBackend(WindowUI* window_ui);
    };
}