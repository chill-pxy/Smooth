#include <iostream>
#include <assert.h>

#include "runtime/tool/global/global_context.h"

#include "runtime/tool/render/render_system.h"
#include "runtime/tool/render/render_pipeline.h"
#include "runtime/resource/config_manager/config_manager.h"
#include "runtime/resource/asset_manager/asset_manager.h"
#include "runtime/resource/global/global_rendering.h"

namespace Smooth
{
    RenderSystem::~RenderSystem()
    {
        clear();
    }

    void RenderSystem::initialize(RenderSystemInitInfo init_info)
    {
        std::shared_ptr<ConfigManager> config_manager = g_runtime_global_context.m_config_manager;
        assert(config_manager);

        std::shared_ptr<AssetManager> asset_manager = g_runtime_global_context.m_asset_manager;
        assert(asset_manager);

        m_render_pipeline = std::make_shared<RenderPipeline>();
        m_render_pipeline->initialize();

        //global rendering resource
        GlobalRendringRes global_rendering_res;
        const std::string& global_rendering_res_url = config_manager->getGlobalRenderingResUrl();
        asset_manager->loadAsset(global_rendering_res_url, global_rendering_res);
        
        //setup render camera
        //const CameraPose& camera_pos = 
    }

    void RenderSystem::tick(float delta_time)
    {
        assert(m_render_pipeline);
        m_render_pipeline->forwardRender();
        m_render_pipeline->deferredRender();
    }

    void RenderSystem::clear()
    {
        m_render_pipeline.reset();
    }

    std::shared_ptr<DefaultCamera> RenderSystem::getRenderCamera() const { return m_render_camera; }

    void RenderSystem::initializeUIRenderBackend(WindowUI* window_ui)
    {
        m_render_pipeline->initializeRenderBackend(window_ui);
    }

    void RenderSystem::updateEngineContentViewport(float offset_x, float offset_y, float width, float height)
    {
        glViewport(offset_x, offset_y, width, height);
    }
}