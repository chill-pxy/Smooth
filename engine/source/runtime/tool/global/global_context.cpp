#include <iostream>

#include "runtime/tool/global/global_context.h"

namespace Smooth
{

    RuntimeGlobalContext runtime_global_context;

    void RuntimeGlobalContext::startSystems()
    {
        std::cout<<"ϵͳ����"<<std::endl;
    }

    void RuntimeGlobalContext::shudownSystems()
    {
        std::cout<<"ϵͳ�ر�"<<std::endl;
    }
}