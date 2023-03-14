#include <iostream>

#include "runtime/engine.h"
#include "runtime/tool/global/global_context.h"

namespace Smooth
{
    void SmoothEngine::startEngine()
    {
        runtime_global_context.startSystems();
        std::cout<<"引擎启动"<<std::endl;
    }

    void SmoothEngine::shutdownEngine()
    {
        runtime_global_context.shudownSystems();
        std::cout<<"引擎关闭"<<std::endl;
    }
}