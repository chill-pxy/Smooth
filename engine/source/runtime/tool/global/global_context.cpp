#include <iostream>

#include "runtime/tool/global/global_context.h"
#include "runtime/tool/render/window_system.h"
#include "runtime/tool/render/render_system.h"
#include "runtime/tool/input/input_system.h"
#include "runtime/resource/config_manager/config_manager.h"

namespace Smooth
{

    RuntimeGlobalContext g_runtime_global_context;

    void RuntimeGlobalContext::startSystems(const std::string& config_file_path)
    {
        //config初始化
        m_config_manager = std::make_shared<ConfigManager>();
        m_config_manager->initialize(config_file_path);

        //窗口系统初始化
        m_window_system = std::make_shared<WindowSystem>();
        WindowInfo window_creat_info;
        m_window_system->initialize(window_creat_info);

        //输入系统初始化
        m_input_system = std::make_shared<InputSystem>();
        m_input_system->initialize();

        //渲染系统初始化
        m_render_system = std::make_shared<RenderSystem>();
        RenderSystemInitInfo render_init_info;
        render_init_info.window_system = m_window_system;
        m_render_system->initialize(render_init_info);

        std::cout<<"系统启动"<<std::endl;
    }

    void RuntimeGlobalContext::shudownSystems()
    {
        m_config_manager.reset();

        m_window_system.reset();

        m_input_system.reset();

        m_render_system.reset();

        std::cout<<"系统关闭"<<std::endl;
    }
}