namespace Smooth
{
    class RuntimeGlobalContext
    {

    public:
        void startSystems();
        void shudownSystems();

    };

    extern RuntimeGlobalContext runtime_global_context;
}