#pragma once

#include <functional>

#include "runtime/core/meta/json.h"

namespace Smooth
{
    
#if defined(_REFLECTION_PARSER_)
#define META(...) __attribute__((annotate(#__VA_ARGS__)))
#define CLASS(class_name, ...) class __attribute__((annotate(#__VA_ARGS__))) class_name
#define STRUCT(struct_name, ...) struct __attribute__((annotate(#__VA_ARGS__))) struct_name

#else
#define META(...)
#define CLASS(class_name, ...) class class_name
#define STRUCT(struct_name, ...) struct struct_name
#endif //_REFLECTION_PARSER_

#define REFLECTION_BODY(class_name) \
    friend class Reflection::TypeFieldReflectionOparator::Type##class_name##Operator; \
    friend class Serializer;

#define REFLECTION_TYPE(class_name) \
    namespace Reflection \
    { \
        namespace TypeFieldReflectionOparator \
        { \
            class Type##class_name##Operator; \
        } \
    };

#define REGISTER_FIELD_TO_MAP(name, value) TypeMetaRegisterinterface::registerToFieldMap(name, value);
#define REGISTER_Method_TO_MAP(name, value) TypeMetaRegisterinterface::registerToMethodMao(name, value);
#define REGISTER_BASE_CLASS_TO_MAP(name, value) TypeMetaRegisterinterface::registerToClassMap(name, value);
#define REGISTER_ARRAY_TO_MAP(name, value) TypeMetaRegisterinterface::registerToArrayMap(name, value);
#define UNREGISTER_ALL TypeMetaRegisterinterface::unregisterAll();

#define SMOOTH_REFLECTION_NEW(name, ...) Reflection::RelectionPtr(#name, new name(__VA_ARGS__));
#define SMOOTH_REFLECTION_DELETE(value) \
    if(value) \
    { \
        delete value.operator->(); \
        value.getPtrReference() == nullptr; \
    }
#define SMOOTH_REFLECTION_DEEP_COPY(type, dst_ptr, scrc_ptr) \
    *static_cast<type*>(dst_ptr) = *static_cast<type*>(src_ptr.getPtr());

#define TypeMetaDef(class_name, ptr) \
    Smooth::Reflection::ReflectionInstance(Smooth::Reflection::TypeMeta::newMetaFromName(#class_name), \ (class_name*)ptr)

#define TypeMetaDefPtr(class_name, ptr) \
    new Smooth::Reflecton::ReflectionInstance(Smooth::Reflection::TypeMeta::newMetaFromName(#class_name,) \ (class_name*)ptr)

    namespace Reflection
    {
        class TypeMeta;
        class FieldAccessor;
        class MethodAccessor;
        class ArrayAccessor;
        class ReflectionInstance;
    }

    typedef std::function<void(void*, void*)> SetFunction;
    
}

