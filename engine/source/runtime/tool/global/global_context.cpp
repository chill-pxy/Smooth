#include <iostream>

#include "runtime/tool/global/global_context.h"
#include "runtime/tool/render/window_system.h"

namespace Smooth
{

    RuntimeGlobalContext g_runtime_global_context;

    void RuntimeGlobalContext::startSystems()
    {
        //窗口系统初始化
        m_window_system = std::make_shared<WindowSystem>();
        WindowInfo window_creat_info;
        m_window_system->initialize(window_creat_info);

        std::cout<<"系统启动"<<std::endl;
    }

    void RuntimeGlobalContext::shudownSystems()
    {
        m_window_system.reset();
        std::cout<<"系统关闭"<<std::endl;
    }
}