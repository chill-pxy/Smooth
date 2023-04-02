#pragma once

#include "runtime/tool/render/render_pass.h"

namespace Smooth
{
    class WindowUI;

    class UIPass : public RenderPass
    {
    public:
        void draw() override final;
    private:
        WindowUI* m_window_ui;
    };
}