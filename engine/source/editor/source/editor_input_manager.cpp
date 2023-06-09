#include <iostream>

#include "editor_input_manager.h"
#include "editor_global_context.h"
#include "editor_scene_manager.h"

#include "runtime/tool/render/window_system.h"

#include "runtime/tool/input/input_system.h"

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
        g_editor_global_context.m_window_system->registerOnCursorPosFunc(std::bind(&EditorInputManager::onCursorPos,
                                                                        this,
                                                                        std::placeholders::_1,
                                                                        std::placeholders::_2));
        g_editor_global_context.m_window_system->registerOnCursorEnter(std::bind(&EditorInputManager::onCursorEnter,
                                                                        this,
                                                                        std::placeholders::_1));
        g_editor_global_context.m_window_system->registerOnWindowClose(std::bind(&EditorInputManager::onWindowClosed,
                                                                        this));
        g_editor_global_context.m_window_system->registerOnMouseButton(std::bind(&EditorInputManager::onMouseButtonClicked,
                                                                        this,
                                                                        std::placeholders::_1,
                                                                        std::placeholders::_2));
    }

    void EditorInputManager::processEditorCommand()
    {
        if((unsigned int)EditorCommand::camera_foward & m_editor_command)
        {
            g_editor_global_context.m_scene_manager->getEditorCamera()->ProcessKeyboard(CameraMovement::FORWARD);
        }
        if((unsigned int)EditorCommand::camera_back & m_editor_command)
        {
            g_editor_global_context.m_scene_manager->getEditorCamera()->ProcessKeyboard(CameraMovement::BACKWARD);
        }
        if((unsigned int)EditorCommand::camera_left & m_editor_command)
        {
            g_editor_global_context.m_scene_manager->getEditorCamera()->ProcessKeyboard(CameraMovement::LEFT);
        }
        if((unsigned int)EditorCommand::camera_right & m_editor_command)
        {
            g_editor_global_context.m_scene_manager->getEditorCamera()->ProcessKeyboard(CameraMovement::RIGHT);
        }   
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
        else if(action == GLFW_RELEASE)
        {
            switch(key)
            {
            case GLFW_KEY_ESCAPE:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::exit;
                break;
            case GLFW_KEY_A:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::camera_left;
                break;
            case GLFW_KEY_S:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::camera_back;
                break;
            case GLFW_KEY_D:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::camera_right;
                break;
            case GLFW_KEY_W:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::camera_foward;
                break;
            case GLFW_KEY_Q:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::camera_up;
                break;
            case GLFW_KEY_E:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::camera_down;
                break;
            case GLFW_KEY_T:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::translation_mode;
                break;
            case GLFW_KEY_R:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::rotation_mode;
                break;
            case GLFW_KEY_C:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::scale_mode;
                break;     
            case GLFW_KEY_DELETE:
                m_editor_command &= (k_complement_control_command) ^ (unsigned int)EditorCommand::delete_object;
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
        
        if(m_mouse_x >= 0.0f && m_mouse_y >= 0.0f)
        {
            if(g_editor_global_context.m_window_system->isMouseButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
            {
                glfwSetInputMode(
                    g_editor_global_context.m_window_system->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                g_editor_global_context.m_scene_manager->getEditorCamera()->ProcessMouseMovement(xpos, ypos);
            }
            else if(g_editor_global_context.m_window_system->isMouseButtonDown(GLFW_MOUSE_BUTTON_LEFT))
            {
                glfwSetInputMode(g_editor_global_context.m_window_system->getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
            else
            {
                glfwSetInputMode(g_editor_global_context.m_window_system->getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
        }
        m_mouse_x = xpos;
        m_mouse_y = ypos;
    }

    void EditorInputManager::onCursorEnter(int entered)
    {
        if(!entered)
        {
            m_mouse_x = m_mouse_y = -1.0f;
        }
    }

    void EditorInputManager::onScroll(double xoffset, double yoffset)
    {
        if(!g_is_editor_mode)
        {
            return;
        }
    }

    void EditorInputManager::onMouseButtonClicked(int key, int action)
    {
        
    }

    void EditorInputManager::onWindowClosed(){ g_editor_global_context.m_engine_runtime->shutdownEngine(); }
}