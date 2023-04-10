#include "editor_scene_manager.h"

namespace Smooth
{
    void EditorSceneManager::initialize()
    {
        m_camera = std::make_shared<DefaultCamera>(vec3(0.0f,0.0f,0.0f));
    }

    void EditorSceneManager::tick(float delta_time)
    {

    }

}