#include "imgui.h"

#include "ui_pass.h"
#include "runtime/tool/ui/window_ui.h"

namespace Smooth
{
    void UIPass::draw()
    {
        if(m_window_ui)
        {
            ImGui::NewFrame();

            m_window_ui->preRender();  //turn to EditorUI::draw()

            ImGui::Render();
        }
    }
}