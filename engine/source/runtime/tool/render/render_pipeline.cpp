#include <iostream>

#include "render_pipeline.h"
#include "runtime/tool/render/passes/ui_pass.h"
#include "runtime/tool/global/global_context.h"

namespace Smooth
{
    void RenderPipeline::initialize()
    {
        m_ui_pass = std::make_shared<UIPass>();

        Shader shader("../engine/shader/skybox.vs", "../engine/shader/skybox.fs");
        m_skybox_shader = shader;
        m_skybox_shader.use();
        m_skybox_shader.setInt("skybox", 0);

        Skybox skybox;
        m_skybox = skybox;

        m_default_camera = new DefaultCamera(vec3(0.0f, 0.0f, 0.0f));
    }

    void RenderPipeline::forwardRender()
    {
		glClearColor(1.0,1.0,1.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mat4 projection = perspective(radians(m_default_camera->m_zoom),
        (float)g_runtime_global_context.m_window_system->getWindowWidth() / 
        (float)g_runtime_global_context.m_window_system->getWindwoHeight(),
        0.1f , 100.0f);
        mat4 view       = m_default_camera->GetViewMatrix();
        vec3 postion    = m_default_camera->m_position;

        m_skybox.draw(m_skybox_shader, projection, view);
    }

    void RenderPipeline::deferredRender()
    {
        //UIPass& ui_pass = *(static_cast<UIPass*>(m_ui_pass.get()));
        static_cast<UIPass*>(m_ui_pass.get())->draw();
    }
}