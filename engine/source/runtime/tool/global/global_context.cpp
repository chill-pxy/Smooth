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
        //config��ʼ��
        m_config_manager = std::make_shared<ConfigManager>();
        m_config_manager->initialize(config_file_path);
        
        //����ϵͳ��ʼ��
        m_window_system = std::make_shared<WindowSystem>();
        WindowInfo window_creat_info;
        m_window_system->initialize(window_creat_info);
        
        //����ϵͳ��ʼ��
        m_input_system = std::make_shared<InputSystem>();
        m_input_system->initialize();

        //��Ⱦϵͳ��ʼ��
        m_render_system = std::make_shared<RenderSystem>();
        RenderSystemInitInfo render_init_info;
        render_init_info.window_system = m_window_system;
        m_render_system->initialize(render_init_info);

        std::cout<<"system started"<<std::endl;
    }

    void RuntimeGlobalContext::shutdownSystems()
    {
        m_config_manager.reset();

        m_window_system.reset();

        m_input_system.reset();

        m_render_system.reset();

        std::cout<<"system shutdown"<<std::endl;
    }
}