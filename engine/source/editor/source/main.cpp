#include <iostream>

#include "runtime/engine.h"
#include "editor.h"

int main()
{
    Smooth::SmoothEngine* engine=new Smooth::SmoothEngine();

    engine->startEngine();
    engine->run();

    Smooth::SmoothEditor* editor=new Smooth::SmoothEditor();
    
    editor->initialize(engine);
    editor->run();

    editor->clear();
    engine->shutdownEngine();

    return 0;
} 