#pragma once

namespace Smooth
{
    class InputSystem
    {
    public:
        void initialize();
        void tick();
        void onKey(int key,int scancode,int action,int mods);
    };
}