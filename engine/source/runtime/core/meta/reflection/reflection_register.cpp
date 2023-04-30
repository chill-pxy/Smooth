#include "runtime/core/meta/reflection/reflection_register.h"
#include "runtime/core/meta/reflection/reflection.h"

namespace Smooth
{
    namespace Reflection
    {
        void TypeMetaRegister::metaUnregister() { TypeMetaRegisterinterface::unregisterAll(); }
    }
}

