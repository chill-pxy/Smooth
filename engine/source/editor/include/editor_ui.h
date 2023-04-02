#pragma once

#include <memory>

#include "runtime/tool/ui/window_ui.h"

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
    
    private:
        bool m_editor_menu_window_open = true;
    };

}