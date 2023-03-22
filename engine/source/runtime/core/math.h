#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "glm/gtc/quaternion.hpp"

using namespace glm;

namespace Smooth
{
    class Vector3 : public glm::vec3
    {
    public:
        float X;
        float Y;
        float Z;

        Vector3() = default;
        Vector3(float x, float y, float z):X(x),Y(y),Z(z){}

    };

    class Quaternion : public glm::qua<float>
    {
    public:
        float W;
        float X;
        float Y;
        float Z;
 
        Quaternion() = default;
        Quaternion(float w, float x, float y, float z):W(w),X(x),Y(y),Z(z){} 

        static const Quaternion IDENTITY;
    };
    const Quaternion Quaternion::IDENTITY(1.0f,0.0f,0.0f,0.0f);


    class Matrix4X4 : public glm::mat4x4
    {
    public:
    };
}