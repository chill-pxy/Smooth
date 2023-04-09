#pragma once

#include "glad/glad.h"

#include "runtime/core/math.h"

namespace Smooth
{
    // Default camera values
    const float DEFAULT_YAW { -90.0f };
    const float DEFAULT_PITCH { 0.0f };
    const float DEFAULT_SPEED { 2.5f };
    const float DEFAULT_SENSITIVITY { 0.1f };
    const float DEFAULT_ZOOM { 45.0f };

    enum CameraMovement
    {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
    };

    class DefaultCamera
    {
    public:
        vec3 m_position;
        vec3 m_front;
        vec3 m_up;
        vec3 m_right;
        vec3 m_worldUp;

        float m_yaw;
        float m_pitch;

        float m_movement_speed;
        float m_mouse_sensitivity;
        float m_zoom;

        explicit DefaultCamera(vec3 position = vec3(0.0f,0.0f,0.0f),
                                vec3  up    = vec3(0.0f,1.0f,0.0f),
                                float yaw   = DEFAULT_YAW,
                                float pitch = DEFAULT_PITCH);

        DefaultCamera(float posX, float posY, float posZ,
                        float upX, float upY, float upZ,
                        float yaw, float pitch);
        
        mat4 GetViewMatrix();
        void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
        void ProcessKeyboard(CameraMovement direction);

    private:
        void UpdateCameraVectors();

    };
}