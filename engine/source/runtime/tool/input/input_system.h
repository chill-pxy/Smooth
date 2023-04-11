#pragma once

#include "runtime/core/math.h"

namespace Smooth
{
    enum class DisplayCommand : unsigned int
    {
        forward  = 1 <<0,
        backward = 1 <<1,
        left     = 1 <<2,
        right    = 2 <<3,
        invalid  = (unsigned int)(1 << 31)
    };

    extern unsigned int k_complement_control_command;
    
    class InputSystem
    {
    public:
        void initialize();
        void tick();
        void clear();
        void calculateCursorDeltaAngles();

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