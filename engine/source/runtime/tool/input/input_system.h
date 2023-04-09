#pragma once

#include "runtime/core/math.h"

namespace Smooth
{
    class InputSystem
    {
    public:
        void initialize();
        void tick();

        void onKey(int key,int scancode,int action,int mods);
        void onCursorPos(double current_cursor_x, double current_cursor_y);

        void         resetDisplayCommand() { m_display_command = 0; }
        unsigned int getDisplayCommand() const { return m_display_command; }

        int m_cursor_delta_x {0};
        int m_cursor_delta_y {0};

        int m_cursor_delta_yaw {0};
        int m_cursor_delta_pitch {0};
    
    private:
        void onKeyInDisplayMode(int key, int scancode, int action, int mods);

        unsigned int m_display_command {0};

        int m_last_cursor_x {0};
        int m_last_cursor_y {0};
    };
}