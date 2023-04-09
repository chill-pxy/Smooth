#define STB_IMAGE_IMPLEMENTATION

#include <math.h>
#include <iostream>

#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "stb_image.h"

#include "editor_ui.h"
#include "editor_global_context.h"
#include "editor_input_manager.h"
#include "editor_scene_manager.h"
#include "editor_global_context.h"
#include "editor_language.h"

#include "runtime/tool/global/global_context.h"

#include "runtime/resource/config_manager/config_manager.h"

#include "engine.h"

#include "runtime/tool/render/window_system.h"
#include "runtime/tool/render/render_system.h"

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
        std::shared_ptr<ConfigManager> config_manager = g_runtime_global_context.m_config_manager;
        assert(config_manager);

        //create imgui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        {
            std::cout<<"failed to load opengl"<<std::endl;
        }

        ImGui_ImplGlfw_InitForOpenGL(init_info.window_system->getWindow(), true);
        ImGui_ImplOpenGL3_Init("#version 330");

        //set ui content scale
        float x_scale,y_scale;
        glfwGetWindowContentScale(init_info.window_system->getWindow(),&x_scale,&y_scale);
        
        float content_scale = fmaxf(1.0f,fmaxf(x_scale,y_scale));
        windowContentScaleUpdate(content_scale);
        glfwSetWindowContentScaleCallback(init_info.window_system->getWindow(),windowContentScaleCallback); 
    
        //docking space
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigDockingAlwaysTabBar         = true;
        io.ConfigWindowsMoveFromTitleBarOnly = true;
        
        //load font
        //io.Fonts->AddFontFromFileTTF(
        //    config_manager->getEditorFontPath().generic_string().data(), content_scale * 16, nullptr, nullptr);
        io.Fonts->AddFontFromFileTTF(
            config_manager->getEditorChineseFontPath().generic_string().data(), content_scale * 16, nullptr, io.Fonts->GetGlyphRangesChineseFull());
        io.Fonts->Build();

        //initialize language
        m_editor_text = g_editor_global_context.m_editor_language->getEditorText();

        ImGuiStyle& style     = ImGui::GetStyle();
        style.WindowPadding   = ImVec2(1.0, 0);
        style.FramePadding    = ImVec2(14.0, 2.0f);
        style.ChildBorderSize = 0.0f;
        style.FrameRounding   = 5.0f;
        style.FrameBorderSize = 1.5f;

        ImGui::StyleColorsDark();

        //setup window icon
        GLFWimage window_icon[2];
        std::string big_icon_path_string   = config_manager->getEditorBigIconPath().generic_string();
        std::string small_icon_path_string = config_manager->getEditorSmallIconPath().generic_string();
        window_icon[0].pixels = 
            stbi_load(big_icon_path_string.data(), &window_icon[0].width, &window_icon[0].height, 0, 4);
        window_icon[1].pixels =
            stbi_load(small_icon_path_string.data(), &window_icon[1].width, &window_icon[1].height, 0, 4);
        glfwSetWindowIcon(init_info.window_system->getWindow(), 2, window_icon);
        stbi_image_free(window_icon[0].pixels);
        stbi_image_free(window_icon[1].pixels);

        init_info.render_system->initializeUIRenderBackend(this);
    }

    void EditorUI::preRender(){showEditorUI();}

    void EditorUI::showEditorUI()
    {
        showEditorMenu(&m_editor_menu_window_open);
        showEditorSceneWindow(&m_editor_scene_window_open);
        showEditorWorldObjectsWindow(&m_editor_worldObjects_window_open);
        showEditorFileContentWindow(&m_editor_fileContent_window_open);
        showEditorDetailWindow(&m_editor_detail_window_open);
        //showTestWindow(&m_editor_menu_window_open);
    }

    void EditorUI::showEditorMenu(bool* p_open)
    {
        ImGuiDockNodeFlags dock_flags   = ImGuiDockNodeFlags_DockSpace;
        ImGuiWindowFlags   window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar |
                                        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                                        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground |
                                        ImGuiConfigFlags_NoMouseCursorChange | ImGuiWindowFlags_NoBringToFrontOnFocus;
        
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(main_viewport->WorkPos, ImGuiCond_Always);
        std::array<int,2> window_size = g_editor_global_context.m_window_system->getWindowSize();
        
        ImGui::SetNextWindowSize(ImVec2((float)window_size[0], (float)window_size[1]), ImGuiCond_Always);
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

            ImGui::DockBuilderDockWindow(m_editor_text.WORLD_OBJECTS.c_str(), left_asset);
            ImGui::DockBuilderDockWindow(m_editor_text.DETAILS.c_str(), right);
            ImGui::DockBuilderDockWindow(m_editor_text.FILE_CONTENT.c_str(), left_file_content);
            ImGui::DockBuilderDockWindow(m_editor_text.SCENE.c_str(), left_game_engine);

            ImGui::DockBuilderFinish(main_docking_id);
        }

        ImGui::DockSpace(main_docking_id);

        if(ImGui::BeginMenuBar())
        {
            if(ImGui::BeginMenu(m_editor_text.MENU.c_str()))
            {
                if(ImGui::MenuItem(m_editor_text.RELOAD_SCENE.c_str()))
                {
                    
                }

                if(ImGui::MenuItem(m_editor_text.SAVE_SCENE.c_str()))
                {

                }

                if(ImGui::MenuItem(m_editor_text.EXIT.c_str()))
                {
                    ImGui_ImplOpenGL3_Shutdown();
                    ImGui_ImplGlfw_Shutdown();
                    ImGui::DestroyContext();
                    g_editor_global_context.m_engine_runtime->shutdownEngine();
                    exit(0);
                }
                ImGui::EndMenu();
            }

            if(ImGui::BeginMenu(m_editor_text.WINDOW.c_str()))
            {
                ImGui::MenuItem(m_editor_text.WORLD_OBJECTS.c_str(), nullptr, &m_editor_worldObjects_window_open);
                ImGui::MenuItem(m_editor_text.SCENE.c_str(), nullptr, &m_editor_scene_window_open);
                ImGui::MenuItem(m_editor_text.FILE_CONTENT.c_str(), nullptr, &m_editor_fileContent_window_open);
                ImGui::MenuItem(m_editor_text.DETAILS.c_str(), nullptr, &m_editor_detail_window_open);
                ImGui::EndMenu();
            }

            if(ImGui::BeginMenu(m_editor_text.LANGUAGE.c_str()))
            {
                if(ImGui::MenuItem("中文", nullptr, &m_editor_language_chinese))
                {
                    g_editor_global_context.m_editor_language->SelectLanguage(LanguageType::Chinese);
                    m_editor_text=g_editor_global_context.m_editor_language->getEditorText();
                    m_editor_language_chinese = true;
                    m_editor_language_english = false;
                }
                if(ImGui::MenuItem("English", nullptr, &m_editor_language_english))
                {
                    g_editor_global_context.m_editor_language->SelectLanguage(LanguageType::English);
                    m_editor_text=g_editor_global_context.m_editor_language->getEditorText();
                    m_editor_language_english = true;
                    m_editor_language_chinese = false;
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::End();
    }

    void EditorUI::showEditorSceneWindow(bool* p_open)
    {
        ImGuiIO& io                        = ImGui::GetIO();
        ImGuiWindowFlags window_flags      = ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_MenuBar |
                                            ImGuiWindowFlags_NoCollapse;
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();

        if(!*p_open)
            return;
        if(!ImGui::Begin(m_editor_text.SCENE.c_str(), p_open, window_flags))
        {
            ImGui::End();
            return;
        }

        static bool trans_button_clicked  = false;
        static bool rotate_button_clicked = false;
        static bool scale_button_clicked  = false;

        switch (g_editor_global_context.m_scene_manager->getEditorAxisMode())
        {
        case EditorAxisMode::TranslateMode:
            trans_button_clicked  = true;
            rotate_button_clicked = false;
            scale_button_clicked  = false;
            break;
        case EditorAxisMode::RotateMode:
            trans_button_clicked  = false;
            rotate_button_clicked = true;
            scale_button_clicked  = false;
            break;
        case EditorAxisMode::ScaleMode:
            trans_button_clicked  = false;
            rotate_button_clicked = false;
            scale_button_clicked  = true;
            break;
        default:
            break;
        }

        if(ImGui::BeginMenuBar())
        {
            ImGui::Indent(10.0f);
            drawAxisToggleButton(m_editor_text.TRANSLATE.c_str(), trans_button_clicked, (int)EditorAxisMode::TranslateMode);
            ImGui::Unindent();

            ImGui::SameLine();
            drawAxisToggleButton(m_editor_text.ROTATE.c_str(), rotate_button_clicked, (int)EditorAxisMode::RotateMode);
            
            ImGui::SameLine();
            drawAxisToggleButton(m_editor_text.SCALE.c_str(), scale_button_clicked, (int)EditorAxisMode::ScaleMode);

            ImGui::SameLine();
            float indent_val = 0.0f;
            float x_scale, y_scale;
            glfwGetWindowContentScale(g_editor_global_context.m_window_system->getWindow(), &x_scale, &y_scale);
            float indent_scale = fmaxf(1.0f, fmaxf(x_scale, y_scale));

            indent_val = g_editor_global_context.m_input_manager->getEngineWindowSize().x - 100.0f * indent_scale;
        
            ImGui::Indent(indent_val);
            ImGui::PushID(m_editor_text.EDITOR_MODE.c_str());
            if(ImGui::Button(m_editor_text.EDITOR_MODE.c_str()))
            {

            }
            ImGui::PopID();
            ImGui::Unindent();
            ImGui::EndMenuBar();
        }

        vec2 render_target_window_pos  = {0.0f, 0.0f};
        vec2 render_target_window_size = {0.0f, 0.0f};

        auto menu_bar_rect = ImGui::GetCurrentWindow()->MenuBarRect();

        render_target_window_pos.x = ImGui::GetWindowPos().x;
        render_target_window_pos.y = menu_bar_rect.Max.y;
        render_target_window_size.x = ImGui::GetWindowSize().x;
        render_target_window_size.y = (ImGui::GetWindowSize().y + ImGui::GetWindowPos().y) - menu_bar_rect.Max.y;

        g_editor_global_context.m_input_manager->setEngineWindowPos(render_target_window_pos);
        g_editor_global_context.m_input_manager->setEngineWinowSize(render_target_window_size);

        ImGui::End();
       
    }

    void EditorUI::showEditorWorldObjectsWindow(bool* p_open)
    {
        ImGuiWindowFlags window_flags      = ImGuiWindowFlags_None;
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();

        if(!*p_open)
            return;

        if(!ImGui::Begin(m_editor_text.WORLD_OBJECTS.c_str(), p_open, window_flags))
        {
            ImGui::End();
            return;
        }

        ImGui::End();
    }

    void EditorUI::showEditorFileContentWindow(bool* p_open)
    {
        ImGuiWindowFlags window_flags      = ImGuiWindowFlags_None;
        static ImGuiTableFlags flags       = ImGuiTableFlags_BordersV | ImGuiTableFlags_BordersOuterH |
                                            ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg |
                                            ImGuiTableFlags_NoBordersInBody;

        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();

        if(!*p_open)
            return;

        if(!ImGui::Begin(m_editor_text.FILE_CONTENT.c_str(), p_open, window_flags))
        {
            ImGui::End();
            return;
        }

        if(ImGui::BeginTable(m_editor_text.FILE_CONTENT.c_str(), 2, flags))
        {
            ImGui::TableSetupColumn(m_editor_text.NAME.c_str(), ImGuiTableColumnFlags_NoHide);
            ImGui::TableSetupColumn(m_editor_text.TYPE.c_str(), ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableHeadersRow();
        }
        ImGui::EndTable();

        ImGui::End();
    }

    void EditorUI::showEditorDetailWindow(bool* p_open)
    {
        ImGuiWindowFlags window_flags      = ImGuiWindowFlags_None;
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();

        if(!*p_open)
            return;

        if(!ImGui::Begin(m_editor_text.DETAILS.c_str(), p_open, window_flags))
        {
            ImGui::End();
            return;
        }

        ImGui::End();
    }

    void EditorUI::drawAxisToggleButton(const char* string_id, bool check_state, int axis_mode)
    {
        if (check_state)
        {
            ImGui::PushID(string_id);
            ImVec4 check_button_color = ImVec4(93.0f / 255.0f, 10.0f / 255.0f, 66.0f / 255.0f, 1.00f);
            ImGui::PushStyleColor(ImGuiCol_Button,
                                  ImVec4(check_button_color.x, check_button_color.y, check_button_color.z, 0.40f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, check_button_color);
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, check_button_color);
            ImGui::Button(string_id);
            ImGui::PopStyleColor(3);
            ImGui::PopID();
        }
        else
        {
            if (ImGui::Button(string_id))
            {
                check_state = true;
                g_editor_global_context.m_scene_manager->setEditorAxisMode((EditorAxisMode)axis_mode);
                //g_editor_global_context.m_scene_manager->drawSelectedEntityAxis();
            }
        }  
    }

}