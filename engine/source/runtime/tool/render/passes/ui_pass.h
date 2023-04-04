#pragma once

#include "runtime/tool/render/render_pass.h"
#include "runtime/tool/render/window_system.h"

namespace Smooth
{
    class WindowUI;

    class UIPass : public RenderPass
    {
    public:
        void draw() override final;
        void initializeUIRenderBackend(WindowUI* window_ui) override final;
    private:
        WindowUI* m_window_ui;
    };
}