#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "ui_pass.h"
#include "runtime/tool/ui/window_ui.h"

namespace Smooth
{
    void UIPass::draw()
    {
        std::cout<<"UIpass begin to draw"<<std::endl;
        assert(m_window_ui);
        if(m_window_ui)
        {
            std::cout<<"m_window_ui is true"<<std::endl;
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            m_window_ui->preRender();  //turn to EditorUI::draw()

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }
        std::cout<<"UIpass end draw"<<std::endl;
    }

    void UIPass::initializeUIRenderBackend(WindowUI* window_ui)
    {
        m_window_ui = window_ui;
    }
}