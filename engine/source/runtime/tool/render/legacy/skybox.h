#pragma once

#include <vector>

#include "runtime/core/math.h"
#include "shader.h"

namespace Smooth
{
    class Skybox
    {
    public:
        Skybox();

        void         draw(Shader skybox_shader, mat4 projection, mat3 camera_view);
        unsigned int loadCubeMap(std::vector<std::string> faces);

    private:
        unsigned int skyboxVAO;
        unsigned int skyboxVBO;
        unsigned int cubeMapTexture;
    };
}