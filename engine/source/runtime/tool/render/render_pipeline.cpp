#include <iostream>

#include "render_pipeline.h"
#include "runtime/tool/render/passes/ui_pass.h"
#include "runtime/tool/global/global_context.h"

namespace Smooth
{
    void RenderPipeline::initialize()
    {
        m_ui_pass = std::make_shared<UIPass>();

        glEnable(GL_DEPTH_TEST);
        m_skybox_shader = std::make_shared<Shader>("../engine/shader/skybox.vs", "../engine/shader/skybox.fs");
        m_skybox_shader->use();
        m_skybox_shader->setInt("skybox", 0);

        m_skybox = std::make_shared<Skybox>();

    }

    void RenderPipeline::forwardRender()
    {
		glClearColor(1.0,1.0,1.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mat4 projection = perspective(radians(g_editor_global_context.m_scene_manager->getEditorCamera()->m_zoom),
        (float)g_runtime_global_context.m_window_system->getWindowWidth() / 
        (float)g_runtime_global_context.m_window_system->getWindwoHeight(),
        0.1f , 100.0f);
        mat4 view       = g_editor_global_context.m_scene_manager->getEditorCamera()->GetViewMatrix();
        vec3 postion    = g_editor_global_context.m_scene_manager->getEditorCamera()->m_position;

        m_skybox->draw(*m_skybox_shader, projection, view);
    }

    void RenderPipeline::deferredRender()
    {
        //UIPass& ui_pass = *(static_cast<UIPass*>(m_ui_pass.get()));
        static_cast<UIPass*>(m_ui_pass.get())->draw();
    }
}