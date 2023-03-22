#include <memory>

#include "runtime/tool/render/default_camera.h"

namespace Smooth
{
    class SmoothEditor;

    enum class EditorCommand : unsigned int
    {
        camera_left   = 1 << 0, //A
        camera_back   = 1 << 1, //S
        camera_foward = 1 << 2, //W
        camera_right  = 1 << 3, //D
        camera_up     = 1 << 4, //Q
        camera_down   = 1 << 5, //E

        translation_mode = 1 << 6, //T
        rotation_mode    = 1 << 7, //R
        scale_mode       = 1 << 8, //C
        exit             = 1 << 9, //ESC
        delete_object    = 1 << 10,//Delete

    };

    class EditorInputManager
    {
    public:
        void initialize();
        void tick(float delta_time);
    
        void registerInput();
        void processEditorCommand();

        void onKey(int key, int scancode, int action, int mods);

    private:
        unsigned int m_editor_command {0};

        float m_mouse_x {0.0f};
        float m_mouse_y {0.0f};
        float m_camera_speed {0.05f};
    };
}