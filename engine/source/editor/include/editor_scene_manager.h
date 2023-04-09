#pragma once

#include <memory>

#include "runtime/tool/render/default_camera.h"

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
        EditorAxisMode                 getEditorAxisMode(){ return m_axis_mode; }
        std::shared_ptr<DefaultCamera> getEditorCamera() {return m_camera;}
        void                           setEditorCamera(std::shared_ptr<DefaultCamera> new_camera){ m_camera = new_camera; }
        void                           setEditorAxisMode(EditorAxisMode new_mode){ m_axis_mode = new_mode; }
    
    private:
        EditorAxisMode                 m_axis_mode{ EditorAxisMode::TranslateMode };
        std::shared_ptr<DefaultCamera> m_camera;
    };
}