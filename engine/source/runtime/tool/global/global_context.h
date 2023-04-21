#pragma once

#include <assert.h>
#include <memory>

namespace Smooth
{
    class WindowSystem;
    class InputSystem;
    class RenderSystem;
    class ConfigManager;
    class AssetManager;

    class RuntimeGlobalContext
    {
    public:
        void startSystems(const std::string& config_file_path);
        void shutdownSystems();
    
    public:
        std::shared_ptr<WindowSystem>  m_window_system;
        std::shared_ptr<InputSystem>   m_input_system;
        std::shared_ptr<RenderSystem>  m_render_system;
        std::shared_ptr<ConfigManager> m_config_manager;
        std::shared_ptr<AssetManager>  m_asset_manager;
    };

    extern RuntimeGlobalContext g_runtime_global_context;
}