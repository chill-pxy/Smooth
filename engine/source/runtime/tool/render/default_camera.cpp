#include "runtime/tool/render/default_camera.h"

namespace Smooth
{
    DefaultCamera::DefaultCamera(vec3 position, vec3 up, float yaw, float pitch)
    :m_position(position),m_worldUp(up),m_yaw(yaw),m_pitch(pitch)
    {
        UpdateCameraVectors();
    }

    DefaultCamera::DefaultCamera(float posX, float posY, float posZ,
                                float upX, float upY, float upZ,
                                float yaw, float pitch)
    :m_position(vec3(posX,posY,posZ)),m_worldUp(vec3(upX,upY,upZ)),
    m_yaw(yaw),m_pitch(pitch),m_front(vec3(0.0f,0.0f,-1.0f)),m_movement_speed(DEFAULT_SPEED),
    m_mouse_sensitivity(DEFAULT_SENSITIVITY),m_zoom(DEFAULT_ZOOM)
    {
        UpdateCameraVectors();
    }

    mat4 DefaultCamera::GetViewMatrix()
    {
        return lookAt(m_position,m_position + m_front , m_up);
    }

    void DefaultCamera::UpdateCameraVectors()
    {
        vec3 front;
        front.x = cos(radians(m_yaw)) * cos(radians(m_pitch));
        front.y = sin(radians(m_pitch));
        front.z = sin(radians(m_yaw)) * cos(radians(m_pitch));
        m_front = normalize(front);
        m_right = normalize(cross(m_front,m_worldUp));
        m_up    = normalize(cross(m_right,m_right));
    }

    void DefaultCamera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
    {
        xoffset *= m_mouse_sensitivity;
        yoffset *= m_mouse_sensitivity;

        m_yaw   += xoffset;
        m_pitch += yoffset;

        // make sure that when m_pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch)
        {
            if (m_pitch > 89.0f)
                m_pitch = 89.0f;
            if (m_pitch < -89.0f)
                m_pitch = -89.0f;
        }

        // update Front, Right and Up Vectors using the updated Euler angles
        UpdateCameraVectors();
    }

}