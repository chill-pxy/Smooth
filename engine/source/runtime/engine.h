namespace Smooth
{
    class SmoothEngine
    {
        friend class SmoothEditor;

    public:
        void startEngine();
        void shutdownEngine();
        void run();
    };
}