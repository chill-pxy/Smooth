#pragma once

namespace Smooth
{
    enum class EditorAxisMode : int
    {
        TranslateMode = 0,
        RotateMode    = 1,
        ScaleMode     = 2,
        Default       = 3
    };

    class EditorSceneManager
    {
    public:
        void initialize();
        void tick(float delta_time);

    public:
        EditorAxisMode getEditorAxisMode(){ return m_axis_mode; }
        void setEditorAxisMode(EditorAxisMode new_mode){ m_axis_mode = new_mode; }

    private:
        EditorAxisMode m_axis_mode{ EditorAxisMode::TranslateMode };
    };
}