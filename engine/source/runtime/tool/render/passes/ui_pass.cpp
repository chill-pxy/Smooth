#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "ui_pass.h"
#include "runtime/tool/ui/window_ui.h"

namespace Smooth
{
    void UIPass::draw()
    {
        if(m_window_ui)
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            m_window_ui->preRender();  //turn to EditorUI::draw()

            ImGui::Render();
        }
    }
}