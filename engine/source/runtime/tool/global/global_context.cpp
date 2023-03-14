#include <iostream>

#include "runtime/tool/global/global_context.h"

namespace Smooth
{

    RuntimeGlobalContext runtime_global_context;

    void RuntimeGlobalContext::startSystems()
    {
        std::cout<<"系统启动"<<std::endl;
    }

    void RuntimeGlobalContext::shudownSystems()
    {
        std::cout<<"系统关闭"<<std::endl;
    }
}