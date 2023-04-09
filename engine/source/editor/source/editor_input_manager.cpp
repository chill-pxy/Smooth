#include "editor_input_manager.h"
#include "editor_global_context.h"
#include "editor_scene_manager.h"

#include "runtime/tool/render/window_system.h"

#include "engine.h"

namespace Smooth
{
    void EditorInputManager::initialize(){ registerInput(); }
    void EditorInputManager::tick(float delta_time){ processEditorCommand(); }

    void EditorInputManager::registerInput()
    {
        g_editor_global_context.m_window_system->registerOnKeyFunc(std::bind(&EditorInputManager::onKey,
                                                                            this,
                                                                            std::placeholders::_1,
                                                                            std::placeholders::_2,
                                                                            std::placeholders::_3,
                                                                            std::placeholders::_4));

    }

    void EditorInputManager::processEditorCommand()
    {
        float camera_speed = m_camera_speed;
    }

    void EditorInputManager::onKey(int key, int scancode, int action, int mods)
    {
        if(g_is_editor_mode)
        {
            onKeyInEditorMode(key, scancode, action, mods);
        }
    }

    void EditorInputManager::onKeyInEditorMode(int key, int scancode, int action, int mods)
    {
        if(action == GLFW_PRESS)
        {
            switch (key)
            {
            case GLFW_KEY_A:
                m_editor_command |= (unsigned int)EditorCommand::camera_left;
                break;
            case GLFW_KEY_S:
                m_editor_command |= (unsigned int)EditorCommand::camera_back;
                break;
            case GLFW_KEY_D:
                m_editor_command |= (unsigned int)EditorCommand::camera_right;
                break;
            case GLFW_KEY_W:
                m_editor_command |= (unsigned int)EditorCommand::camera_foward;
                break;
            case GLFW_KEY_Q:
                m_editor_command |= (unsigned int)EditorCommand::camera_up;
                break;
            case GLFW_KEY_E:
                m_editor_command |= (unsigned int)EditorCommand::camera_down;
                break;
            case GLFW_KEY_T:
                m_editor_command |= (unsigned int)EditorCommand::translation_mode;
                break;
            case GLFW_KEY_R:
                m_editor_command |= (unsigned int)EditorCommand::rotation_mode;
                break;
            case GLFW_KEY_C:
                m_editor_command |= (unsigned int)EditorCommand::scale_mode;
                break;     
            case GLFW_KEY_DELETE:
                m_editor_command |= (unsigned int)EditorCommand::delete_object;
                break;           
            
            default:
                break;
            }
        }
    }

    void EditorInputManager::onCursorPos(double xpos, double ypos)
    {
        if(!g_is_editor_mode)
            return;
        
        g_editor_global_context.m_scene_manager->getEditorCamera()->ProcessMouseMovement(xpos, ypos);
        
    }
}