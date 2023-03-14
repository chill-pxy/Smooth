#include <assert.h>
#include <iostream>

#include "editor.h"

namespace Smooth
{
    void SmoothEditor::initialize(SmoothEngine* engine_runtime)
    {
        assert(engine_runtime);
        m_engine_runtime=engine_runtime;
        
        std::cout<<"�༭����ʼ��"<<std::endl;
    }

    void SmoothEditor::clear()
    {
        std::cout<<"�༭���ر�"<<std::endl;
    }

    void SmoothEditor::run()
    {
        std::cout<<"�༭������"<<std::endl;
    }
}