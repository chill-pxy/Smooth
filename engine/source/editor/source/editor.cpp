#include <assert.h>
#include <iostream>

#include "editor.h"

namespace Smooth
{
    void SmoothEditor::initialize(SmoothEngine* engine_runtime)
    {
        assert(engine_runtime);
        m_engine_runtime=engine_runtime;
        
        std::cout<<"±à¼­Æ÷³õÊ¼»¯"<<std::endl;
    }

    void SmoothEditor::clear()
    {
        std::cout<<"±à¼­Æ÷¹Ø±Õ"<<std::endl;
    }

    void SmoothEditor::run()
    {
        std::cout<<"±à¼­Æ÷Æô¶¯"<<std::endl;
    }
}