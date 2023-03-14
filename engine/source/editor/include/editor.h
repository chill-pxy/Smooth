#include <memory>

namespace Smooth
{
    class EditorUI;
    class SmoothEngine;

    class SmoothEditor
    {
        friend class EditorUI;

    public:
        void initialize(SmoothEngine* engine_runtime);
        void clear();
        void run();

    protected:
        std::shared_ptr<EditorUI> m_editor_ui;
        SmoothEngine* m_engine_runtime{ nullptr };

    };
}