#include <memory>

#include "runtime/tool/render/render_pipeline_base.h"

namespace Smooth
{
    class WindowSystem;
    class WindowUI;

    struct RenderSystemInitInfo
    {
        std::shared_ptr<WindowSystem> window_system;
    };

    struct EngineContentViewport
    {
        float x {0.f};
        float y {0.f};
        float weight {0.f};
        float height {0.f};
    };

    class RenderSystem
    {
    public:
        RenderSystem() = default;
        ~RenderSystem();

        void initialize(RenderSystemInitInfo init_info);
        void tick(float delta_time);
        void clear();

        void initializeUIRenderBackend(WindowUI* window_ui);
        void updateEngineContentViewport(float offset_x, float offset_y, float width, float height);
    
    private:
        std::shared_ptr<RenderPipelineBase> m_render_pipeline;

    };
}