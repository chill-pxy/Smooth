#pragma once

#include <memory>

#include "runtime/tool/ui/window_ui.h"
#include "editor_language.h"

namespace Smooth
{
    class SmoothEditor;
    class RenderSystem;
    class WindowSystem;
    
    class EditorUI : public WindowUI
    {
    public:
        EditorUI();
        virtual void initialize(WindowUIInitInfo init_info) override final;
        virtual void preRender() override final;
    
    private:
        void showEditorUI();
        void showEditorMenu(bool* p_open);
        void showEditorSceneWindow(bool* p_open);
        void showEditorWorldObjectsWindow(bool* p_open);
        void showEditorFileContentWindow(bool* p_open);
        void showEditorDetailWindow(bool* p_open);

        void drawAxisToggleButton(const char* string_id, bool check_state, int axis_mode);

    private:
        EditorText m_editor_text;

        bool m_editor_menu_window_open         = true;
        bool m_editor_scene_window_open        = true;
        bool m_editor_worldObjects_window_open = true;
        bool m_editor_fileContent_window_open  = true;
        bool m_editor_detail_window_open       = true;

        bool m_editor_language_chinese = true;
        bool m_editor_language_english = false;
    };

}