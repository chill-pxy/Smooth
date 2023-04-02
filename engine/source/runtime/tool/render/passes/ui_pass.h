#pragma once

#include "runtime/tool/render/render_pass.h"

namespace Smooth
{
    class WindowUI;

    class UIPass : RenderPass
    {
    public:
        void draw();
    private:
        WindowUI* m_window_ui;
    };
}