#include <math.h>
#include <iostream>

#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "editor_ui.h"
#include "editor_global_context.h"

#include "runtime/tool/render/window_system.h"
#include "runtime/tool/render/render_system.h"

#include "engine.h"

namespace Smooth
{
    EditorUI::EditorUI()
    {

    }

    inline void windowContentScaleUpdate(float scale)
    {
#if defined(__GNUC__) && defined(__MACH__)
        float font_scale               = fmaxf(1.0f, scale);
        ImGui::GetIO().FontGlobalScale = 1.0f / font_scale;
#endif
        // TOOD: Reload fonts if DPI scale is larger than previous font loading DPI scale
    }

    inline void windowContentScaleCallback(GLFWwindow* window, float x_scale, float y_scale)
    {
        windowContentScaleUpdate(fmaxf(x_scale, y_scale));
    }

    void EditorUI::initialize(WindowUIInitInfo init_info)
    {
        //create imgui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGui_ImplGlfw_InitForOpenGL(init_info.window_system->getWindow(), true);
        ImGui_ImplOpenGL3_Init("#version 330");

        //std::cout<<"imgui opengl success"<<std::endl;

        //set ui content scale
        float x_scale,y_scale;
        glfwGetWindowContentScale(init_info.window_system->getWindow(),&x_scale,&y_scale);
        
        float content_scake = fmaxf(1.0f,fmaxf(x_scale,y_scale));
        windowContentScaleUpdate(content_scake);
        glfwSetWindowContentScaleCallback(init_info.window_system->getWindow(),windowContentScaleCallback); 
    
        //docking space
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigDockingAlwaysTabBar         = true;
        io.ConfigWindowsMoveFromTitleBarOnly = true;

        init_info.render_system->initializeUIRenderBackend(this);
    }

    void EditorUI::preRender(){showEditorUI();}

    void EditorUI::showEditorUI()
    {
        showEditorMenu(&m_editor_menu_window_open);
        //showTestDock(&m_editor_menu_window_open);
    }

    void EditorUI::showEditorMenu(bool* p_open)
    {
        ImGuiDockNodeFlags dock_flags   = ImGuiDockNodeFlags_DockSpace;
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar |
                                        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                                        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground |
                                        ImGuiConfigFlags_NoMouseCursorChange | ImGuiWindowFlags_NoBringToFrontOnFocus;
        
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(main_viewport->WorkPos, ImGuiCond_Always);
        std::array<int,2> window_size = g_editor_global_context.m_window_system->getWindowSize();
        ImGui::SetNextWindowViewport(main_viewport->ID);

        ImGui::Begin("Editor Menu", p_open, window_flags);
        
        ImGuiID main_docking_id = ImGui::GetID("Main Docking");
        if(ImGui::DockBuilderGetNode(main_docking_id) == nullptr)
        {
            ImGui::DockBuilderRemoveNode(main_docking_id);

            ImGui::DockBuilderAddNode(main_docking_id, dock_flags);
            ImGui::DockBuilderSetNodePos(main_docking_id,
                                            ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y + 18.0f));
            ImGui::DockBuilderSetNodeSize(main_docking_id,
                                            ImVec2((float)window_size[0], (float)window_size[1] - 18.0f));

            ImGuiID center = main_docking_id;
            ImGuiID left;
            ImGuiID right = ImGui::DockBuilderSplitNode(center, ImGuiDir_Right, 0.25f, nullptr, &left);

            ImGuiID left_other;
            ImGuiID left_file_content = ImGui::DockBuilderSplitNode(left, ImGuiDir_Down, 0.30f, nullptr, &left_other);

            ImGuiID left_game_engine;
            ImGuiID left_asset = ImGui::DockBuilderSplitNode(left_other, ImGuiDir_Left, 0.30f, nullptr, &left_game_engine);

            ImGui::DockBuilderDockWindow("World Objects", left_asset);
            ImGui::DockBuilderDockWindow("Components Details", right);
            ImGui::DockBuilderDockWindow("File Content", left_file_content);
            ImGui::DockBuilderDockWindow("Game Engine", left_game_engine);

            ImGui::DockBuilderFinish(main_docking_id);
        }

        ImGui::DockSpace(main_docking_id);

        if(ImGui::BeginMenuBar())
        {
            if(ImGui::BeginMenu("Menu"))
            {
                if(ImGui::MenuItem("Reload Current Scene")){}

                if(ImGui::MenuItem("Save Current Scene")){}

                if(ImGui::MenuItem("Exit"))
                {
                    g_editor_global_context.m_engine_runtime->shutdownEngine();
                    exit(0);
                }
                ImGui::EndMenu();
            }
            
            if(ImGui::BeginMenu("Window"))
            {
                ImGui::MenuItem("World Objects", nullptr, &m_editor_menu_window_open);
                ImGui::MenuItem("Game", nullptr, &m_editor_menu_window_open);
                ImGui::MenuItem("File Content", nullptr, &m_editor_menu_window_open);
                ImGui::MenuItem("Details", nullptr, &m_editor_menu_window_open);
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::End();
    }

    void EditorUI::showTestDock(bool* p_open)
    {
        ImGuiDockNodeFlags dock_flags   = ImGuiDockNodeFlags_DockSpace;
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar |
                                        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                                        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground |
                                        ImGuiConfigFlags_NoMouseCursorChange | ImGuiWindowFlags_NoBringToFrontOnFocus;
        
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(main_viewport->WorkPos, ImGuiCond_Always);
        std::array<int,2> window_size = g_editor_global_context.m_window_system->getWindowSize();
        ImGui::SetNextWindowViewport(main_viewport->ID);

        ImGui::Begin("Editor Menu", p_open, window_flags);
        
        ImGuiID main_docking_id = ImGui::GetID("Main Docking");
        ImGui::DockSpace(main_docking_id, ImVec2(0.0f, 0.0f), dock_flags);

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Options"))
            {
                // Disabling fullscreen would allow the window to be moved to the front of other windows,
                // which we can't undo at the moment without finer window depth/z control.
                ImGui::MenuItem("Fullscreen", NULL, true);
                ImGui::MenuItem("Padding", NULL, false);
                ImGui::Separator();

                if (ImGui::MenuItem("Flag: NoSplit",                "", (dock_flags & ImGuiDockNodeFlags_NoSplit) != 0))                 { dock_flags ^= ImGuiDockNodeFlags_NoSplit; }
                if (ImGui::MenuItem("Flag: NoResize",               "", (dock_flags & ImGuiDockNodeFlags_NoResize) != 0))                { dock_flags ^= ImGuiDockNodeFlags_NoResize; }
                if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dock_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0))  { dock_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode; }
                if (ImGui::MenuItem("Flag: AutoHideTabBar",         "", (dock_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0))          { dock_flags ^= ImGuiDockNodeFlags_AutoHideTabBar; }
                if (ImGui::MenuItem("Flag: PassthruCentralNode",    "", (dock_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, true)) { dock_flags ^= ImGuiDockNodeFlags_PassthruCentralNode; }
                ImGui::Separator();

                if (ImGui::MenuItem("Close", NULL, false, p_open != NULL))
                    *p_open = false;
                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }

        ImGui::End();
    }

}