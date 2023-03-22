#include "runtime/tool/render/render_camera.h"

namespace Smooth
{
    void RenderCamera::move(vec3 delta)
    {
        m_position += delta;
    }

    void RenderCamera::rotate(vec2 delta)
    {
        delta = vec2(radians(degrees(delta.x)),radians(degrees(delta.y)));

        float angle = dot(m_up_axis,forward());
        if((angle < -0.99f && delta.x > 0.0f) || 
           (angle > 0.99f && delta.x < 0.0f))
           delta.x = 0.0f;

        fquat pitch,yaw;
        pitch = angleAxis(radians(delta.x),X);
        yaw   = angleAxis(radians(delta.y),Z);

        m_rotation    = pitch * m_rotation * yaw;
        m_invRotation = conjugate(m_rotation);

    }

    void RenderCamera::zoom(float offset)
    {
        m_fovx = clamp(m_fovx - offset ,MIN_FOV, MAX_FOV);
    }

    void RenderCamera::lookAt(const vec3& position, const vec3& target, const vec3& up)
    {
        
    }
}