#include <vector>

#include "runtime/core/math.h"

namespace Smooth
{
    class RenderCamera
    {
    public:
        static const vec3 X,Y,Z;

        vec3  m_position {0.0f,0.0f,0.0f};
        vec3  m_up_axis {Z};
        fquat m_rotation {1,0,0,0};
        fquat m_invRotation {1,0,0,0};
        float m_znear {1000.0f};
        float m_zfar {0.1f};

        static constexpr float MIN_FOV {10.0f};
        static constexpr float MAX_FOV {89.0f};
        static constexpr float MAIN_VIEW_MATRIX_INDEX {0};

        std::vector<mat4x4> m_view_matrices;

        void move(vec3 delta);
        void rotate(vec2 delta);
        void zoom(float offset);
        void lookAt(const vec3& position, const vec3& target, const vec3& up);

        vec3  position() const {return m_position;}
        fquat rotation() const {return m_rotation;}

        vec3 forward() const {return (m_invRotation * Y);}
        vec3 up() const {return (m_invRotation * Z);}
        vec3 right() const {return (m_invRotation * X);}

    protected:
        float m_aspect {0.0f};
        float m_fovx { degrees(89.0f) };
        float m_fovy {0.0f};
    };

    inline const vec3 RenderCamera::X = {1.0f,0.0f,0.0f};
    inline const vec3 RenderCamera::Y = {0.0f,1.0f,0.0f};
    inline const vec3 RenderCamera::Z = {0.0f,0.0f,1.0f};
}