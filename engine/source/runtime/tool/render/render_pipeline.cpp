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

    }

    void RenderPipeline::forwardRender()
    {
		glClearColor(1.0,1.0,1.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mat4 projection = perspective(radians(g_editor_global_context.m_scene_manager->getEditorCamera()->m_zoom),
        (float)g_runtime_global_context.m_window_system->getWindowWidth() / 
        (float)g_runtime_global_context.m_window_system->getWindwoHeight(),
        0.1f , 100.0f);
        mat4 view       = g_editor_global_context.m_scene_manager->getEditorCamera()->GetViewMatrix();
        vec3 postion    = g_editor_global_context.m_scene_manager->getEditorCamera()->m_position;

        std::cout<<postion[0]<<std::endl;
        std::cout<<postion[1]<<std::endl;
        std::cout<<postion[2]<<std::endl;
        m_skybox.draw(m_skybox_shader, projection, view);
    }

    void RenderPipeline::deferredRender()
    {
        //UIPass& ui_pass = *(static_cast<UIPass*>(m_ui_pass.get()));
        static_cast<UIPass*>(m_ui_pass.get())->draw();
    }
}