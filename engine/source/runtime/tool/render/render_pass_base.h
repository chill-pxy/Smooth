#pragma once

namespace Smooth
{
    class RenderPassBase
    {
    public:
        virtual void initialize();
        virtual void preparePassData();
    };
}