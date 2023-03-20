#include <memory>

namespace Smooth
{
    class WindowSystem;

    struct RenderSystemInitInfo
    {
        std::shared_ptr<WindowSystem> window_system;
    };

    class RenderSystem
    {
    public:
        void initialize(RenderSystemInitInfo init_info);
        void tick();

    };
}