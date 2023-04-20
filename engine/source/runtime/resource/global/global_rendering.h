#pragma once

#include <string>

#include "runtime/core/math.h"
#include "runtime/core/meta/reflection/reflection.h"

namespace Smooth
{
    REFLECTION_TYPE(SkyBoxIrradianceMap)
    CLASS(SkyBoxIrradianceMap, Fields)
    {
        REFLECTION_BODY(SkyBoxIrradianceMap);
    
    public:
        std::string m_negative_x_map;
        std::string m_positive_x_map;
        std::string m_negative_y_map;
        std::string m_positive_y_map;
        std::string m_negative_z_map;
        std::string m_positive_z_map;
    };

    REFLECTION_TYPE(SkyBoxSpecularMap)
    CLASS(SkyBoxSpecularMap, Fields)
    {
        REFLECTION_BODY(SkyBoxSpecularMap);

    public:
        std::string m_negative_x_map;
        std::string m_positive_x_map;
        std::string m_negative_y_map;
        std::string m_positive_y_map;
        std::string m_negative_z_map;
        std::string m_positive_z_map;    
    };

    REFLECTION_TYPE(DirectionalLight)
    CLASS(DirectionalLight, Fields)
    {
        REFLECTION_BODY(DirectionalLight);
    
    public:
        vec3 m_direction;
        vec3 m_color;
    };

    REFLECTION_TYPE(GlobalRenderingRes)
    CLASS(GlobalRendringRes, Fields)
    { 
        REFLECTION_BODY(GlobalRenderingRes);
    
    public:
        bool                m_enable_fxaa {false};
        SkyBoxIrradianceMap m_skybox_irradiance_map;
        SkyBoxSpecularMap   m_skybox_specular_map;
        std::string         m_brdf_map;
        std::string         m_color_grading_map;
    };
}